/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:18:05 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/15 09:27:49 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*scpy;

	i = 0;
	scpy = s;
	if (c > 256)
		c -= 256;
	if (((!scpy || !c) && !n) \
		|| !n)
		return (NULL);
	while (scpy[i] != c)
	{
		i++;
		if (i == n)
			return (NULL);
		if (i > n)
			return ((void *)scpy);
	}
	return ((void *)scpy + i);
}
