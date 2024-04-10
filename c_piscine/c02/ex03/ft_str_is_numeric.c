/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:11:47 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/26 11:38:53 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	return_value;

	i = 0;
	return_value = 0;
	if (str [i] == '\0')
	{
		return_value = 1;
	}
	while (str [i] >= '1' && str [i] <= '9')
	{
		i++;
		if (str [i] == '\0')
		{
			return_value = 1;
		}
	}
	return (return_value);
}
