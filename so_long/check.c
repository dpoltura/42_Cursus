/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:54:33 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:46:44 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char **map, t_data *data)
{
	int	y;
	int	x;
	int	size;

	y = 0;
	x = 0;
	while (data->tab[y][x])
		x++;
	size = x;
	y++;
	while (data->tab[y])
	{
		x = 0;
		while (data->tab[y][x])
			x++;
		if (y == (data->window_height / 32) - 1)
			x++;
		if (size != x)
			not_rectangular(map, data);
		size = x;
		y++;
	}
	if (y < 2)
		error(data);
}

void	check_wall(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->tab[y])
	{
		while (data->tab[y][x])
		{
			if ((y == 0 || y == (data->window_height / 32) - 1)
				&& (data->tab[y][x] != '1' && data->tab[y][x] != '\n'))
				not_surrounded(map, data);
			if ((x == 0 || x == (data->window_width / 32) - 1)
				&& (data->tab[y][x] != '1' && data->tab[y][x] != '\n'))
				not_surrounded(map, data);
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_epc(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->tab[y])
	{
		while (data->tab[y][x])
		{
			if (data->tab[y][x] == 'E')
				data->epc[0]++;
			else if (data->tab[y][x] == 'P')
				data->epc[1]++;
			else if (data->tab[y][x] == 'C')
				data->epc[2]++;
			x++;
		}
		x = 0;
		y++;
	}
	if (data->epc[0] != 1 || data->epc[1] != 1 || data->epc[2] < 1)
		not_contain_epc(map, data);
}

void	check_characters(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->tab[y])
	{
		while (data->tab[y][x])
		{
			if (data->tab[y][x] != 'E' && data->tab[y][x] != 'P'
				&& data->tab[y][x] != 'C' && data->tab[y][x] != '0'
				&& data->tab[y][x] != '1' && data->tab[y][x] != '\n')
			{
				free_map(map);
				ft_printf("bad characters in map: ");
				error(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_all(t_data *data)
{
	char	**map;

	map = clone_map(data);
	check_rectangle(map, data);
	check_wall(map, data);
	check_epc(map, data);
	check_characters(map, data);
	char_pos(data);
	floodfill(data->x, data->y, map, data);
	check_after_floodfill(map, data);
	free_map(map);
	data->x = 0;
	data->y = 0;
}
