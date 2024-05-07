/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:13:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/05/07 09:11:02 by dpoltura         ###   ########.fr       */
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
	pthread_mutex_lock(&tmp->table->var_mutex);
	if (!tmp->last_meal)
	{
		if ((time.tv_sec - tmp->table->time_of_day.tv_sec) * 1000000 > tmp->time_to_die)
		{
			pthread_mutex_unlock(&tmp->l_fork_mutex);
			pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
			pthread_mutex_unlock(&tmp->r_fork_mutex);
			pthread_mutex_unlock(&tmp->next->l_fork_mutex);
			pthread_mutex_lock(&tmp->table->print_mutex);
			printf("philo %d "ANSI_BOLDRED_HI"died\n"ANSI_RESET, tmp->philo_nb);
			pthread_mutex_unlock(&tmp->table->print_mutex);
			tmp->table->end = 1;
			pthread_mutex_unlock(&tmp->table->var_mutex);
			return (0);
		}
	}
	else
	{
		if ((time.tv_sec - tmp->last_meal) * 1000000 > tmp->time_to_die)
		{
			pthread_mutex_unlock(&tmp->l_fork_mutex);
			pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
			pthread_mutex_unlock(&tmp->r_fork_mutex);
			pthread_mutex_unlock(&tmp->next->l_fork_mutex);
			pthread_mutex_lock(&tmp->table->print_mutex);
			printf("philo %d "ANSI_BOLDRED_HI"died\n"ANSI_RESET, tmp->philo_nb);
			pthread_mutex_unlock(&tmp->table->print_mutex);
			tmp->table->end = 1;
			pthread_mutex_unlock(&tmp->table->var_mutex);
			return (0);
		}
	}
	pthread_mutex_unlock(&tmp->l_fork_mutex);
	pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
	pthread_mutex_unlock(&tmp->r_fork_mutex);
	pthread_mutex_unlock(&tmp->next->l_fork_mutex);
	pthread_mutex_unlock(&tmp->table->var_mutex);
	return (1);
}
static void	philo_is_eating(t_philos *tmp)
{
	struct timeval	time;
	
	pthread_mutex_lock(&tmp->l_fork_mutex);
	pthread_mutex_lock(&tmp->prev->r_fork_mutex);
	pthread_mutex_lock(&tmp->r_fork_mutex);
	pthread_mutex_lock(&tmp->next->l_fork_mutex);
	pthread_mutex_lock(&tmp->table->print_mutex);
	printf("philo %d is "ANSI_BOLDGREEN_HI"eating\n"ANSI_RESET, tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->print_mutex);
	pthread_mutex_lock(&tmp->table->var_mutex);
	usleep(tmp->time_to_eat);
	gettimeofday(&time, NULL);
	tmp->last_meal = time.tv_sec;
	pthread_mutex_unlock(&tmp->table->var_mutex);
	pthread_mutex_unlock(&tmp->l_fork_mutex);
	pthread_mutex_unlock(&tmp->prev->r_fork_mutex);
	pthread_mutex_unlock(&tmp->r_fork_mutex);
	pthread_mutex_unlock(&tmp->next->l_fork_mutex);
}

static void	philo_is_sleeping(t_philos *tmp)
{
	pthread_mutex_lock(&tmp->table->print_mutex);
	printf("philo %d is "ANSI_BOLDYELLOW_HI"sleeping\n"ANSI_RESET, tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->print_mutex);
	pthread_mutex_lock(&tmp->table->var_mutex);
	usleep(tmp->time_to_sleep);
	pthread_mutex_unlock(&tmp->table->var_mutex);
}

static void	philo_is_thinking(t_philos *tmp)
{
	pthread_mutex_lock(&tmp->table->print_mutex);
	printf("philo %d is "ANSI_BOLDBLUE_HI"thinking\n"ANSI_RESET, tmp->philo_nb);
	pthread_mutex_unlock(&tmp->table->print_mutex);
}

static void	*routine(void *cursor)
{
	t_philos	*tmp;

	tmp = cursor;
	if (!philo_is_die(tmp) || tmp->table->end == 1)
		return (NULL);
	philo_is_eating(tmp);
	if (!philo_is_die(tmp) || tmp->table->end == 1)
		return (NULL);
	philo_is_sleeping(tmp);
	if (!philo_is_die(tmp) || tmp->table->end == 1)
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
