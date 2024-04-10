/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:51:30 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/09 12:29:52 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	total;

	total = nmemb * size;
	if (!total)
		return (malloc(1));
	if (nmemb > INT_MAX || size > INT_MAX)
		return (NULL);
	if (!nmemb || !size)
		return (NULL);
	res = (char *)malloc(total);
	if (!res)
		return (NULL);
	ft_memset(res, 0, total);
	return ((void *)res);
}
