/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:37:45 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/09 15:16:28 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_n_to_tab(long n, int count_n, char *s)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	s[count_n] = '\0';
	count_n--;
	while (count_n >= 0)
	{
		i = n % 10;
		n = n / 10;
		if (s[count_n] != '-')
			s[count_n] = i + '0';
		count_n--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		count_n;

	count_n = ft_count(n);
	res = ft_calloc(sizeof(char), count_n + 1);
	if (!res)
		return (res);
	res = ft_n_to_tab(n, count_n, res);
	return (res);
}
