/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:44:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/22 15:48:13 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table **table)
{
	t_philos	*cursor;
	t_philos	*tmp;

	cursor = (*table)->philos;
	free((*table)->args);
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
	free(*table);
}
