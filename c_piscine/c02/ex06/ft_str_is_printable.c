/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:12:15 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/26 11:39:48 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	return_value;

	i = 0;
	return_value = 0;
	if (str [i] == '\0')
	{
		return_value = 1;
	}
	while (str [i] >= 32 && str [i] <= 126)
	{
		i++;
		if (str [i] == '\0')
		{
			return_value = 1;
		}
	}
	return (return_value);
}
