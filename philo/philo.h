/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:40:56 by dpoltura          #+#    #+#             */
/*   Updated: 2024/05/15 10:02:26 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct	s_args
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_meals;
}	t_args;

typedef struct s_philos
{
	struct s_table	*table;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int	nb_of_meals;
	time_t	last_meal;
	int	philo_nb;
	pthread_t	thread;
	pthread_mutex_t	l_fork_mutex;
	pthread_mutex_t r_fork_mutex;
	struct s_philos	*prev;
	struct s_philos	*next;
}	t_philos;

typedef struct	s_table
{
	struct timeval	time_of_day;
	int		end;
	pthread_t	end_thread;
	pthread_t	meal_thread;
	t_args	*args;
	t_philos	*philos;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	var_mutex;
}	t_table;

int     ft_atoi(const char *nptr);
int	init_table(t_table **table, char **argv);
void	free_table(t_table **table);
void	create_thread(t_table *table);

#endif
