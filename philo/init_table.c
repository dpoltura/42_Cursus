/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2024/05/15 10:06:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_args(t_args **args, char **argv)
{
	*args = malloc(sizeof(t_args));
	if (!(*args))
		return (0);
	(*args)->nb_of_philos = ft_atoi(argv[1]);
	if (!(*args)->nb_of_philos)
		return (0);
	(*args)->time_to_die = ft_atoi(argv[2]) * 1000;
	if (!(*args)->time_to_die)
		return (0);
	(*args)->time_to_eat = ft_atoi(argv[3]) * 1000;
	if (!(*args)->time_to_eat)
		return (0);
	(*args)->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (!(*args)->time_to_sleep)
		return (0);
	if (argv[5])
		(*args)->nb_of_meals = ft_atoi(argv[5]);
	else
		(*args)->nb_of_meals = 0;
	if (!(*args)->nb_of_meals)
		return (0);
	return (1);
}

static int	init_philos(t_table **table)
{
	t_philos	*cursor;
	t_philos	*tmp;
	int	i;
	int	j;
	
	(*table)->philos = malloc(sizeof(t_philos));
	if (!(*table)->philos)
		return (0);
	cursor = (*table)->philos;
	i = 0;
	j = (*table)->args->nb_of_philos;
	gettimeofday(&(*table)->time_of_day, NULL);
	(*table)->end = 0;
	(*table)->end_thread = 0;
	(*table)->meal_thread = 0;
	while (i < j)
	{
		cursor->table = *table;
		cursor->time_to_die = (*table)->args->time_to_die;
		cursor->time_to_eat = (*table)->args->time_to_eat;
		cursor->time_to_sleep = (*table)->args->time_to_sleep;
		cursor->nb_of_meals = (*table)->args->nb_of_meals;
		cursor->last_meal = 0;
		cursor->philo_nb = i + 1;
		cursor->thread = 0;
		if (i == 0)
			cursor->prev = NULL;
		else
			cursor->prev = tmp;
		if ((i + 1) < j)
		{
			cursor->next = malloc(sizeof(t_philos));
			if (!cursor->next)
				return (0);
			tmp = cursor;
			cursor = cursor->next;
		}
		else
		{
			(*table)->philos->prev = cursor;
			cursor->next = (*table)->philos;
		}
		i++;
	}
	return (1);
}

static int	init_mutex(t_table **table)
{
	t_philos	*cursor;
	int	i;

	cursor = (*table)->philos;
	pthread_mutex_init(&(*table)->print_mutex, NULL);
	pthread_mutex_init(&(*table)->var_mutex, NULL);
	i = 0;
	while (i < (*table)->args->nb_of_philos)
	{
		pthread_mutex_init(&cursor->l_fork_mutex, NULL);
		pthread_mutex_init(&cursor->r_fork_mutex, NULL);
		cursor = cursor->next;
		i++;
	}
	return (1);
}

int	init_table(t_table **table, char **argv)
{
	*table = malloc(sizeof(t_table));
	if (!(*table))
		return (0);
	(*table)->end = 0;
	if (!init_args(&(*table)->args, argv))
		return (0);
	if (!init_philos(table))
		return (0);
	init_mutex(table);
	return (1);
}
