/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:34:48 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/24 06:11:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	r;
	int	nbr;
	int	i;

	i = ft_numlen(n);
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	if (n > INT_MIN && n <= INT_MAX)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		r = n % 10;
		nbr = n / 10;
		r += 48;
		if (nbr > 0)
			ft_putnbr_fd(nbr, fd);
		write(fd, &r, 1);
		if (n == 0)
			n++;
	}
	return (i);
}
