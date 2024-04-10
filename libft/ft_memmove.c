/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:44:13 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/03 10:10:04 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p1;
	const char	*p2;

	i = 0;
	p1 = dest;
	p2 = src;
	if (!dest && !src)
		return (NULL);
	if (src >= dest)
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else
		while (n--)
			p1[n] = p2[n];
	return (dest);
}
