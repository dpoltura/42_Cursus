/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:13:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/05/15 11:25:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*eaten_enough(void *cursor)
{
	t_philos	*tmp;
	int			nb_of_meals;

	tmp = cursor;
	nb_of_meals = 0;
	if (tmp->nb_of_meals == -1)
		return (NULL);
	while (tmp->philo_nb != 1)
		tmp = tmp->prev;
	while (1)
	{
		if (tmp->nb_of_meals > nb_of_meals)
			nb_of_meals = tmp->nb_of_meals;
		tmp = tmp->next;
		if (tmp->philo_nb == 1)
			break ;
	}
	if (!nb_of_meals)
	{
		pthread_mutex_lock(&tmp->table->var_mutex);
		tmp->table->end = 1;
		pthread_mutex_unlock(&tmp->table->var_mutex);
	}
	return (NULL);
}

static void	*philo_is_die(void *cursor)
{
	t_philos	*tmp;
	struct timeval	time;

	tmp = cursor;
	while (tmp->philo_nb != 1)
		tmp = tmp->prev;
	while (1)
	{
		gettimeofday(&time, NULL);
		if ((!tmp->last_meal
			&& (time.tv_usec - tmp->table->time_of_day.tv_usec) > tmp->time_to_die)
			|| (tmp->last_meal
			&& (time.tv_usec - tmp->last_meal) > tmp->time_to_die))
		{
			if (tmp->table->end == 0)
			{
				pthread_mutex_lock(&tmp->table->print_mutex);
				printf("%ld %d died\n", time.tv_usec / 1000, tmp->philo_nb);
				pthread_mutex_unlock(&tmp->table->print_mutex);
				pthread_mutex_lock(&tmp->table->var_mutex);
				tmp->table->end = 1;
				pthread_mutex_unlock(&tmp->table->var_mutex);
			}
			return (NULL);
		}
		tmp = tmp->next;
		if (tmp->philo_nb == 1)
			break ;
	}
	return (NULL);
}
static void	philo_is_eating(t_philos *tmp)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&tmp->l_fork_mutex);
	pthread_mutex_lock(&tmp->prev->r_fork_mutex);
	pthread_mutex_lock(&tmp->r_fork_mutex);
	pthread_mutex_lock(&tmp->next->l_fork_mutex);
	pthread_mutex_lock(&tmp->table->var_mutex);
	tmp->nb_of_meals--;
	tmp->last_meal = time.tv_usec;
	pthread_mutex_unlock(&tmp->table->var_mutex);
	pthread_mutex_lock(&tmp->table->print_mutex);
	if (tmp->table->end == 0)
		printf("%ld %d is eating\n", time.tv_usec / 1000, tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->print_mutex);
	usleep(tmp->time_to_eat);
	pthread_mutex_unlock(&tmp->l_fork_mutex);
	pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
	pthread_mutex_unlock(&tmp->r_fork_mutex);
	pthread_mutex_unlock(&tmp->next->l_fork_mutex);
}

static void	philo_is_sleeping(t_philos *tmp)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&tmp->table->print_mutex);
	if (tmp->table->end == 0)
		printf("%ld %d is sleeping\n", time.tv_usec / 1000, tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->print_mutex);
	usleep(tmp->time_to_sleep);
}

static void	philo_is_thinking(t_philos *tmp)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&tmp->table->print_mutex);
	if (tmp->table->end == 0)
		printf("%ld %d is thinking\n", time.tv_usec / 1000, tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->print_mutex);
}

static void	*routine(void *cursor)
{
    t_philos	*tmp;

    tmp = cursor;
    while (1)
	{
        pthread_mutex_lock(&tmp->table->var_mutex);
        if (tmp->table->end)
		{
            pthread_mutex_unlock(&tmp->table->var_mutex);
            break;
        }
        pthread_mutex_unlock(&tmp->table->var_mutex);
		if (!tmp->nb_of_meals)
			return (NULL);
        philo_is_eating(tmp);
        philo_is_sleeping(tmp);
        philo_is_thinking(tmp);
    }
    return (NULL);
}

void	create_thread(t_table *table)
{
	t_philos	*cursor;
	int	i;
	
	cursor = table->philos;
	i = 0;
	while (table->end == 0)
	{
		while (i < table->args->nb_of_philos && table->end == 0)
		{
			pthread_create(&table->meal_thread, NULL, &eaten_enough, cursor);
			pthread_create(&table->end_thread, NULL, &philo_is_die, cursor);
			pthread_create(&cursor->thread, NULL, &routine, cursor);
			pthread_join(table->meal_thread, NULL);
			pthread_join(table->end_thread, NULL);
			cursor = cursor->next;
			i++;
		}
		cursor = table->philos;
		i = 0;
		while (i < table->args->nb_of_philos && table->end == 0)
		{
			pthread_join(cursor->thread, NULL);
			cursor = cursor->next;
			i++;
		}
		i = 0;
	}
}
