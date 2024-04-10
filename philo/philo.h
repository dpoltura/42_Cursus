/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:40:56 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/12 09:42:59 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*============= INCLUDES =============*/

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*============= COLORS =============*/

# define BOLD "\033[1m"
# define RESET "\033[38;5;15m"
# define RED "\033[38;5;196m"
# define GREEN "\033[38;5;46m"
# define YELLOW "\033[38;5;226m"
# define BLUE "\033[38;5;21m"

/*============= STRUCTS =============*/

typedef struct s_philo
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_of_philos;
	int				num_of_meals;
}					t_philo;

typedef struct s_thread
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	struct s_thread	*prev;
	struct s_thread	*next;
}					t_thread;

/*============= FUNCTIONS =============*/

void	*safe_malloc(int bytes);
void	check_args(int argc, char **argv);
void	error_exit(const char *str);ex
int					ft_atoi(const char *nptr);
void				init_philo(t_philo *philo, char **argv);
void				print_philo(t_philo *philo);
void				*init_thread(t_thread **thread, t_philo *philo);
void				init_thread_values(t_thread *thread);
void				free_thread(t_thread *thread);
void				create_thread(t_thread *thread);
void				*routine(void *param);

#endif