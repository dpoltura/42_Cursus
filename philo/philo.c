/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:46:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 09:44:35 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_args(t_args *args)
{
	printf("table->args:\n");
	printf("args->nb_of_philos: %d\n", args->nb_of_philos);
	printf("args->time_to_die: %d\n", args->time_to_die);
	printf("args->time_to_eat: %d\n", args->time_to_eat);
	printf("args->time_to_sleep: %d\n", args->time_to_sleep);
}

static void	print_philos(t_philos *philos)
{
	while (philos)
	{
		printf("table->philos:\n");
		printf("philos->time_to_die: %d\n", philos->time_to_die);
		printf("philos->time_to_eat: %d\n", philos->time_to_eat);
		printf("philos->time_to_sleep: %d\n", philos->time_to_sleep);
		printf("philos->last_meal: %d\n", philos->last_meal);
		printf("philos->philo_nb: "ANSI_BOLDGREEN_HI"%d"ANSI_RESET"\n", philos->philo_nb);
		printf("philos->thread: %lu\n", philos->thread);
		printf("\n");
		philos = philos->next;
	}
}

static void	print_table(t_table *table)
{
	printf("\n");
	print_args(table->args);
	printf("\n");
	print_philos(table->philos);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc != 5)
		return (1);
	if (!init_table(&table, argv))
		return (1);
	create_thread(table);
	
	print_table(table);
	free_table(&table);
	return (0);
}
