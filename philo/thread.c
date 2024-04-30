/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:13:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 09:47:14 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *cursor)
{
	t_philos	*tmp;

	tmp = cursor;
	printf("philo %d started his thread\n", tmp->philo_nb);
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
	pthread_mutex_destroy(&table->mutex);
}
