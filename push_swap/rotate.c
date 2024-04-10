/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:11 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 16:38:04 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack, int choice)
{
	t_list	*last;
	t_list	*first;
	t_list	*new_last;

	if (!(*stack) || !(*stack)->next)
		return (0);
	last = *stack;
	first = *stack;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	*stack = last;
	if (choice == 1)
		putstr("rra\n", 1);
	else if (choice == 2)
		putstr("rrb\n", 1);
	return (1);
}

int	rotate(t_list **stack, int choice)
{
	t_list	*first;
	t_list	*new_first;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	new_first = (*stack)->next;
	new_first->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	*stack = new_first;
	if (choice == 1)
		putstr("ra\n", 1);
	else if (choice == 2)
		putstr("rb\n", 1);
	return (1);
}

int	reverse_rotate_all(t_list **stack_a, t_list **stack_b)
{
	if (!reverse_rotate(stack_a, 0) && !reverse_rotate(stack_b, 0))
		return (0);
	putstr("rrr\n", 1);
	return (1);
}

int	rotate_all(t_list **stack_a, t_list **stack_b)
{
	if (!rotate(stack_a, 0) && !rotate(stack_b, 0))
		return (0);
	putstr("rr\n", 1);
	return (1);
}
