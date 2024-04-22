/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:46:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/22 14:18:01 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func1(void)
{
	printf("t1\n");
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	
	pthread_t	t1;
	pthread_t	t2;
	
	pthread_create(&t1, NULL, func1, NULL);
	return (0);
}
