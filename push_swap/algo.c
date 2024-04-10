/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:25:43 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 19:52:04 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack, int choice)
{
	if ((*stack)->nbr < (*stack)->next->nbr)
		return ;
	else if (choice == 1)
		swap(stack, 1);
	else if (choice == 2)
		swap(stack, 2);
}

void	sort_three(t_list **stack_a)
{
	while (check_if_sorted(stack_a) == 1)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			swap(stack_a, 1);
		else if ((*stack_a)->nbr < (*stack_a)->next->nbr)
			reverse_rotate(stack_a, 1);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	size = list_size(stack_a);
	i = 1;
	while (i <= size)
	{
		index_list(stack_a, i);
		i++;
	}
	while ((*stack_a)->index != 1)
		rotate(stack_a, 1);
	push_b(stack_a, stack_b);
	while ((*stack_a)->index != 2)
		rotate(stack_a, 1);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	bit;
	int	max_nb;
	int	i;

	max_nb = list_size(stack_a);
	bit = 0;
	index_list_final(stack_a);
	while (check_if_sorted(stack_a) == 1)
	{
		i = 0;
		while (i < max_nb && (*stack_a))
		{
			if ((((*stack_a)->index >> bit) & 1) == 1)
				rotate(stack_a, 1);
			else
				push_b(stack_a, stack_b);
			i++;
		}
		while (list_size(stack_b))
			push_a(stack_b, stack_a);
		bit++;
	}
}

void	algo(t_list **stack_a, t_list **stack_b)
{
	if (list_size(stack_a) == 2)
		sort_two(stack_a, 1);
	else if (list_size(stack_a) == 3)
		sort_three(stack_a);
	else if (list_size(stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
