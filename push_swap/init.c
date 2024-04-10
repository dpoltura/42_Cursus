/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:11:58 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 22:49:37 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bool(t_bool *boolean)
{
	int	i;

	if (boolean->boolean == 0)
		i = 0;
	else
		i = 1;
	return (i);
}

void	atoi_argv(t_list *first, t_list **stack, char **argv, t_bool *boolean)
{
	t_list	*prev;
	int		i;

	prev = NULL;
	i = check_bool(boolean);
	while (argv[i])
	{
		reset(boolean);
		(*stack)->nbr = ft_atoi(argv[i], boolean);
		if ((*stack)->nbr > INT_MAX)
			error_atoi(first, stack, boolean, argv);
		(*stack)->index = 0;
		if (argv[i + 1])
		{
			(*stack)->next = (t_list *)malloc(sizeof(t_list));
			if (!(*stack)->next)
				error_atoi(first, stack, boolean, argv);
		}
		(*stack)->prev = prev;
		prev = *stack;
		if (argv[i + 1])
			*stack = (*stack)->next;
		(*stack)->next = NULL;
		i++;
	}
}

void	init(t_list **stack, char **argv, t_bool *boolean)
{
	t_list	*first;

	if (*stack)
		error(stack, boolean, argv);
	*stack = (t_list *)malloc(sizeof(t_list));
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	if (!(*stack))
		error(stack, boolean, argv);
	first = *stack;
	atoi_argv(first, stack, argv, boolean);
	(*stack)->next = NULL;
	*stack = first;
}

void	reset(t_bool *boolean)
{
	boolean->i = 0;
	boolean->j = 1;
	boolean->k = 0;
}
