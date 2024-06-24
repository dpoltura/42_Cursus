/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:14:27 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/24 13:18:36 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_to_data(t_data_map *data_map)
{
	static int	j = 0;
	
	if (!data_map->map)
	{
		data_map->map = malloc(sizeof(char *) * 100);
		if (!data_map->map)
			return ;
	}
	if (!data_map->line)
	{
		data_map->map[j] = NULL;
		return ;
	}
	data_map->map[j] = ft_strdup(data_map->line);
	j++;
}

int	not_double_player(t_data_map *data_map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (data_map->map[j])
	{
		while (data_map->map[j][i])
		{
			if (data_map->map[j][i] == 'N' || data_map->map[j][i] == 'S'
				|| data_map->map[j][i] == 'W' || data_map->map[j][i] == 'E')
				player++;
			i++;
		}
		i = 0;
		j++;
	}
	if (player != 1)
		return (0);
	return (1);
}

int	map_is_well_spaced(t_data_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data_map->map[j])
	{
		while (data_map->map[j][i])
		{
			if (data_map->map[j][i] == '0')
			{
				if (data_map->map[j][i - 1] != 'N' && data_map->map[j][i - 1] != 'S'
					&& data_map->map[j][i - 1] != 'W' && data_map->map[j][i - 1] != 'E'
					&& data_map->map[j][i + 1] != 'N' && data_map->map[j][i + 1] != 'S'
					&& data_map->map[j][i + 1] != 'W' && data_map->map[j][i + 1] != 'E'
					&& data_map->map[j + 1] && data_map->map[j + 1][i] != 'N' && data_map->map[j + 1][i] != 'S'
					&& data_map->map[j + 1][i] != 'W' && data_map->map[j + 1][i] != 'E'
					&& j && data_map->map[j - 1][i] != 'N' && data_map->map[j - 1][i] != 'S'
					&& data_map->map[j - 1][i] != 'W' && data_map->map[j - 1][i] != 'E'
					&& ((data_map->map[j][i + 1] != '0' && data_map->map[j][i + 1] != '1')
					|| (data_map->map[j + 1] && data_map->map[j + 1][i] != '0' && data_map->map[j + 1][i] != '1')
					|| (j && data_map->map[j - 1][i] != '0' && data_map->map[j - 1][i] != '1')))
					return (0);
			}
			else if (data_map->map[j][i] == 'N' || data_map->map[j][i] == 'S'
					|| data_map->map[j][i] == 'W' || data_map->map[j][i] == 'E')
			{
				if ((data_map->map[j][i - 1] != '0' && data_map->map[j][i - 1] != '1')
					|| (data_map->map[j][i + 1] != '0' && data_map->map[j][i + 1] != '1')
					|| (data_map->map[j + 1] && data_map->map[j + 1][i] != '0' && data_map->map[j + 1][i] != '1')
					|| (j && data_map->map[j - 1][i] != '0' && data_map->map[j - 1][i] != '1'))
					return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	map_is_closed(t_data_map *data_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data_map->map[j])
	{
		if (!j || !data_map->map[j + 1])
		{
			while (data_map->map[j][i])
			{
				if (data_map->map[j][i] != '1' && data_map->map[j][i] != ' ' && data_map->map[j][i] != '\n')
					return (0);
				i++;
			}
		}
		else
		{
			while (data_map->map[j][i])
				i++;
			if (data_map->map[j][i - 2] != '1')
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

int	map_exist(char *str, t_data_map *data_map)
{
	int	i;

	i = 0;
	close(data_map->fd);
	data_map->fd = open(str, O_RDONLY);
	if (data_map->fd < 0)
		return (0);
	free(data_map->line);
	data_map->line = get_next_line(data_map->fd);
	data_map->map = NULL;
	while (data_map->line)
	{
		while (data_map->line && data_map->line[0] == '\n')
		{
			if (data_map->map)
				return (0);
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
		}
		while (data_map->line && data_map->line[i] == ' ')
			i++;
		if (data_map->line && data_map->line[i] != 'N' && data_map->line[i] != 'S'
			&& data_map->line[i] != 'W' && data_map->line[i] != 'E' && data_map->line[i] != '1'
			&& data_map->line[i] != 'F' && data_map->line[i] != 'C' && data_map->line[i] != '\n')
			return (0);
		else if (data_map->line && data_map->line[i] == '1')
			map_to_data(data_map);
		else if (data_map->line && data_map->line[i] != '1' && data_map->map)
			return (0);
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
		i = 0;
	}
	map_to_data(data_map);
	return (1);
}
