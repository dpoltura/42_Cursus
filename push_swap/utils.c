/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:14:07 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/21 22:45:44 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	putnbr(int nbr)
{
	char	c;
	long	n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= (-1);
	}
	if (n != 0)
	{
		c = n % 10 + '0';
		putnbr(n / 10);
		write(1, &c, 1);
	}
}

void	error_atoi(t_list *first, t_list **stack_a, t_bool *boolean,
		char **argv)
{
	*stack_a = first;
	error(stack_a, boolean, argv);
}

long	ft_atoi(const char *nptr, t_bool *boolean)
{
	while ((nptr[boolean->i] >= 9 && nptr[boolean->i] <= 13)
		|| nptr[boolean->i] == 32)
		boolean->i++;
	if (nptr[boolean->i] == '+' || nptr[boolean->i] == '-')
	{
		if (nptr[boolean->i] == '-')
			boolean->j = -1;
		boolean->i++;
	}
	if (nptr[boolean->i] == '\0')
		return (LONG_MAX);
	while (nptr[boolean->i] >= '0' && nptr[boolean->i] <= '9')
	{
		boolean->k = boolean->k * 10;
		boolean->k += nptr[boolean->i] - '0';
		if ((boolean->k * boolean->j) < INT_MIN || (boolean->k
				* boolean->j) > INT_MAX)
			return (LONG_MAX);
		boolean->i++;
	}
	while (nptr[boolean->i] == 32)
		boolean->i++;
	if (nptr[boolean->i] != '\0')
		return (LONG_MAX);
	return (boolean->k * boolean->j);
}

void	free_list(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
