/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:04:31 by dpoltura          #+#    #+#             */
/*   Updated: 2023/10/03 14:11:20 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*n_str;
	int		i;

	n_str = NULL;
	i = 0;
	n_str = malloc(sizeof(char) * *src);
	if (n_str == NULL)
		return (NULL);
	while (src [i] != '\0')
	{
		n_str [i] = src [i];
		i++;
	}
	n_str [i] = '\0';
	return (n_str);
}
