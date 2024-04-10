/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:57:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:51:27 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->tab[y])
	{
		x = 0;
		while (data->tab[y][x] != 'P' && data->tab[y][x] != '\n')
			x++;
		if (data->tab[y][x] == 'P')
			break ;
		y++;
	}
	data->y = y;
	data->x = x;
}

void	floodfill(int x, int y, char **map, t_data *data)
{
	if (x < 0 || x >= data->window_width / 32 || y < 0
		|| y >= data->window_height / 32 || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	floodfill(x + 1, y, map, data);
	floodfill(x - 1, y, map, data);
	floodfill(x, y + 1, map, data);
	floodfill(x, y - 1, map, data);
}

void	check_after_floodfill(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
			{
				free_map(map);
				ft_printf("map path: ");
				error(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

char	**clone_map(t_data *data)
{
	char	**map;
	int		y;

	map = ft_calloc(sizeof(char *), 100);
	if (!map)
	{
		ft_printf("clone_map->ft_calloc: ");
		error(data);
	}
	y = 0;
	while (data->tab[y])
	{
		map[y] = ft_strdup(data->tab[y]);
		y++;
	}
	return (map);
}
