/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:30:47 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/22 10:18:30 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	charactere;
	int	i;

	i = 0;
	while (str [i] != '\0')
	{
		charactere = str [i];
		write(1, &charactere, 1);
		i++;
	}
}
