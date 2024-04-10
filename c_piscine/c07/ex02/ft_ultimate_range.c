/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:04:47 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/10 15:49:51 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*r;

	i = 0;
	r = NULL;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	r = malloc(sizeof(int) * (max - min));
	if (r == NULL)
		return (-1);
	while (min < max)
	{
		r[i] = min;
		i++;
		min++;
	}
	*range = r;
	return (i);
}
