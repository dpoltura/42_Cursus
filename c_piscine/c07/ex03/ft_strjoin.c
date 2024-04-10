/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:08:57 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/11 10:24:15 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest [i] != '\0')
	{
		i++;
	}
	while (src [j] != '\0')
	{
		dest [i] = src [j];
		i++;
		j++;
	}
	dest [i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str [i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_ultimate_strlen(char **strs, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strlen(strs[i]);
		i++;
	}
	return (j);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concatenated_strs;
	int		i;
	int		sep_len;
	int		valloc;

	i = 0;
	sep_len = ft_strlen(sep);
	valloc = sep_len * (size - 1) + ft_ultimate_strlen(strs, size);
	if (size == 0)
		return (malloc(sizeof(char) * 0));
	concatenated_strs = malloc(sizeof(char) * valloc);
	while (i < size)
	{
		ft_strcat(concatenated_strs, strs[i]);
		if (i != size - 1)
			ft_strcat(concatenated_strs, sep);
		i++;
	}
	return (concatenated_strs);
}
