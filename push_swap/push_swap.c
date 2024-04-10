/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/22 11:41:34 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bool	*boolean;

	stack_a = NULL;
	stack_b = NULL;
	boolean = malloc(sizeof(t_bool));
	if (!boolean)
		error(&stack_a, NULL, NULL);
	boolean->boolean = 1;
	if (argc < 2)
		error_no_msg(NULL, boolean, argv);
	if (argc == 2)
	{
		boolean->boolean = 0;
		argv = ft_split(argv[1], ' ');
	}
	init(&stack_a, argv, boolean);
	check_double(&stack_a, boolean, argv);
	algo(&stack_a, &stack_b);
	free_list(&stack_a);
	if (boolean->boolean == 0)
		free_argv(argv);
	free(boolean);
	return (0);
}
