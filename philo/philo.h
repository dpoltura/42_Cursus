/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:40:56 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 09:44:23 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_args
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_args;

typedef struct s_philos
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	last_meal;
	int	philo_nb;
	pthread_t	thread;
	struct s_philos	*prev;
	struct s_philos	*next;
}	t_philos;

typedef struct	s_table
{
	pthread_mutex_t	mutex;
	t_args	*args;
	t_philos	*philos;
}	t_table;

int     ft_atoi(const char *nptr);
int	init_table(t_table **table, char **argv);
void	free_table(t_table **table);
void	create_thread(t_table *table);

#endif

