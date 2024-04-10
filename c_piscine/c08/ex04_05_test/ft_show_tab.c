/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:32:24 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/12 10:03:29 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "ft_stock_str.h"

int     ft_strlen(char *str);

void	ft_putstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		write(1, &str [i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	r;
	int	nbr;

	if (nb == INT_MIN)
		write(1, "-2147483648", 11);
	if (nb > INT_MIN && nb <= INT_MAX)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		r = nb % 10;
		nbr = nb / 10;
		r += 48;
		if (nbr > 0)
			ft_putnbr(nbr);
		write(1, &r, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
