/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:42:08 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:51:42 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	items(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->tab[y])
	{
		while (data->tab[y][x])
		{
			if (data->tab[y][x] == 'C')
				data->items += 1;
			x++;
		}
		x = 0;
		y++;
	}
}

void	count_items(t_data *data)
{
	if (data->tab[data->char_y / 32][data->char_x / 32] == 'C')
	{
		data->tab[data->char_y / 32][data->char_x / 32] = '0';
		data->count_items += 1;
	}
}
