/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:30:18 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/09 16:12:01 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i])
		i++;
	if (!set[i])
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	j = ft_strlen(s1);
	while (!ft_is_in_set(s1[i], set))
		i++;
	while (j > i && !ft_is_in_set(s1[j - 1], set))
		j--;
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
