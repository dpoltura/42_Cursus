/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:46:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/05/15 09:26:02 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	struct timeval	time;

	table = NULL;
	if (argc < 5 || argc > 6)
		return (1);
	if (!init_table(&table, argv))
		return (1);
	if (table->args->nb_of_philos == 1)
	{
		usleep(table->args->time_to_die);
		gettimeofday(&time, NULL);
		printf("%ld %d died\n", time.tv_usec / 1000, table->philos->philo_nb);
		free_table(&table);
		return (1);
	}
	create_thread(table);
	free_table(&table);
	return (0);
}
