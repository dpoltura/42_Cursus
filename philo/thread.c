/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:13:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 11:41:12 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *cursor)
{
	t_philos	*tmp;
	struct timeval	time;

	tmp = cursor;
	sleep(10);
	gettimeofday(&time, NULL);
	pthread_mutex_lock(&tmp->table->mutex);
	if (time.tv_sec - tmp->table->time_of_day.tv_sec > tmp->time_to_die)
		printf("philo %d is died\n", tmp->philo_nb);
	printf("philo %d started his thread\n", tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->mutex);
	return (NULL);
}

void	create_thread(t_table *table)
{
	t_philos	*cursor;
	
	cursor = table->philos;
	while (cursor)
	{
		pthread_create(&cursor->thread, NULL, &routine, cursor);
		cursor = cursor->next;
	}
	cursor = table->philos;
	while (cursor)
	{
		pthread_join(cursor->thread, NULL);
		cursor = cursor->next;
	}
}
