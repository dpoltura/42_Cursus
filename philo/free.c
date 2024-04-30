/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:44:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/30 12:20:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table **table)
{
	t_philos	*cursor;
	t_philos	*tmp;
	int	i;

	cursor = (*table)->philos;
	i = 0;
	while (i < (*table)->args->nb_of_philos)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
		i++;
	}
	free((*table)->args);
	free(*table);
}
