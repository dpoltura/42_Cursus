/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:13:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 17:10:18 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_is_die(t_philos *tmp)
{
	struct timeval	time;

	pthread_mutex_lock(&tmp->l_fork_mutex);
	pthread_mutex_lock(&tmp->prev->r_fork_mutex);
	pthread_mutex_lock(&tmp->r_fork_mutex);
	pthread_mutex_lock(&tmp->next->l_fork_mutex);
	gettimeofday(&time, NULL);
	if ((time.tv_sec - tmp->table->time_of_day.tv_sec) * 1000000 > tmp->time_to_die)
	{
		printf("philo %d is died\n", tmp->philo_nb);
		tmp->table->end = 1;
		return (0);
	}
	pthread_mutex_unlock(&tmp->l_fork_mutex);
	pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
	pthread_mutex_unlock(&tmp->r_fork_mutex);
	pthread_mutex_unlock(&tmp->next->l_fork_mutex);
	return (1);
}
static void	philo_is_eating(t_philos *tmp)
{
	pthread_mutex_lock(&tmp->l_fork_mutex);
	pthread_mutex_lock(&tmp->prev->r_fork_mutex);
	pthread_mutex_lock(&tmp->r_fork_mutex);
	pthread_mutex_lock(&tmp->next->l_fork_mutex);
	printf("philo %d is eating\n", tmp->philo_nb);
	usleep(tmp->time_to_eat);
	pthread_mutex_unlock(&tmp->l_fork_mutex);
	pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
	pthread_mutex_unlock(&tmp->r_fork_mutex);
	pthread_mutex_unlock(&tmp->next->l_fork_mutex);
}

static void	philo_is_sleeping(t_philos *tmp)
{
	printf("philo %d is sleeping\n", tmp->philo_nb);
	usleep(tmp->time_to_sleep);
}

static void	philo_is_thinking(t_philos *tmp)
{
	printf("philo %d is thinking\n", tmp->philo_nb);
}

static void	*routine(void *cursor)
{
	t_philos	*tmp;

	tmp = cursor;
	if (!philo_is_die(tmp))
		return (NULL);
	philo_is_eating(tmp);
	if (!philo_is_die(tmp))
		return (NULL);
	philo_is_sleeping(tmp);
	if (!philo_is_die(tmp))
		return (NULL);
	philo_is_thinking(tmp);
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
			pthread_create(&cursor->thread, NULL, &routine, cursor);
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
