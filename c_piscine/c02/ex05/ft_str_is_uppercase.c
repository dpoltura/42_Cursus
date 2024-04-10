/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:12:04 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/26 11:39:28 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	return_value;

	i = 0;
	return_value = 0;
	if (str [i] == '\0')
	{
		return_value = 1;
	}
	while (str [i] >= 'A' && str [i] <= 'Z')
	{
		i++;
		if (str [i] == '\0')
		{
			return_value = 1;
		}
	}
	return (return_value);
}
