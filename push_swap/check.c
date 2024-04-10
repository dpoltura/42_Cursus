/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:41:51 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/16 16:02:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_list **stack_a, t_bool *boolean, char **argv)
{
	t_list	*current;
	t_list	*cursor;

	current = *stack_a;
	cursor = (*stack_a)->next;
	while (current)
	{
		while (cursor)
		{
			if (cursor->nbr == current->nbr)
				error(stack_a, boolean, argv);
			cursor = cursor->next;
		}
		current = current->next;
		if (current)
			cursor = current->next;
	}
}
