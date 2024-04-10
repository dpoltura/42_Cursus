/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:11:38 by dpoltura          #+#    #+#             */
/*   Updated: 2023/09/26 11:38:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	return_value;

	i = 0;
	return_value = 0;
	if (str [i] == '\0')
	{
		return_value = 1;
	}
	while ((str [i] >= 'a' && str [i] <= 'z')
		|| (str [i] >= 'A' && str [i] <= 'Z'))
	{
		i++;
		if (str [i] == '\0')
		{
			return_value = 1;
		}
	}
	return (return_value);
}
