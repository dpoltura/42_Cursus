/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:15:34 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 22:48:05 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error_no_msg(t_list **stack_a, t_bool *boolean, char **argv)
{
	if (stack_a)
		free_list(stack_a);
	if (boolean && boolean->boolean == 0)
		free_argv(argv);
	free(boolean);
	exit(EXIT_FAILURE);
}

void	error(t_list **stack_a, t_bool *boolean, char **argv)
{
	if (stack_a)
		free_list(stack_a);
	if (boolean && boolean->boolean == 0)
		free_argv(argv);
	free(boolean);
	putstr("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	check(t_list **stack_a, char **argv, t_bool *boolean)
{
	int	i;

	if (boolean->boolean == 0)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		reset(boolean);
		if (ft_atoi(argv[i], boolean) > INT_MAX)
			error(stack_a, boolean, argv);
		i++;
	}
	return (1);
}
