/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:11:37 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 13:53:52 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_args(t_args **args, char **argv)
{
	*args = malloc(sizeof(t_args));
	if (!(*args))
		return (0);
	(*args)->nb_of_philos = ft_atoi(argv[1]);
	(*args)->time_to_die = ft_atoi(argv[2]);
	(*args)->time_to_eat = ft_atoi(argv[3]);
	(*args)->time_to_sleep = ft_atoi(argv[4]);
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
	while (i < j)
	{
		cursor->table = *table;
		cursor->time_to_die = (*table)->args->time_to_die;
		cursor->time_to_eat = (*table)->args->time_to_eat;
		cursor->time_to_sleep = (*table)->args->time_to_sleep;
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
	i = 0;
	while (i < (*table)->args->nb_of_philos)
	{
		pthread_mutex_init(&cursor->l_fork_mutex, NULL);
		cursor->prev->r_fork_mutex = cursor->l_fork_mutex;	
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
