/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:32:14 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/28 11:14:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

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
