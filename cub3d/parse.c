/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:48:09 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/18 11:14:33 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color(t_data_map *data_map)
{
	int	i;
	int	color_nb;

	i = 0;
	color_nb = 0;
	while (color_nb < 2)
	{
		while (data_map->line[0] == '\n')
		{
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
		}
		while (data_map->line[i] == ' ')
			i++;
		if ((data_map->line[i] != 'F' && data_map->line[i] != 'C')
			|| (data_map->line[i] == 'F' && data_map->line[i + 1] != ' ')
			|| (data_map->line[i] == 'C' && data_map->line[i + 1] != ' '))
		{
			close(data_map->fd);
			free(data_map->line);
			return (0);
		}
		else
		{
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
			color_nb++;
		}
	}
	return (1);
}

int	check_texture(t_data_map *data_map)
{
	int	i;
	int	texture_nb;

	i = 0;
	texture_nb = 0;
	while (texture_nb < 4)
	{
		while (data_map->line[0] == '\n')
		{
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
		}
		while (data_map->line[i] == ' ')
			i++;
		if ((data_map->line[i] != 'N' && data_map->line[i] != 'S' && data_map->line[i] != 'W' && data_map->line[i] != 'E')
			|| (data_map->line[i] == 'N' && data_map->line[i + 1] != 'O' && data_map->line[i + 1] != ' ')
			|| (data_map->line[i] == 'S' && data_map->line[i + 1] != 'O' && data_map->line[i + 1] != ' ')
			|| (data_map->line[i] == 'W' && data_map->line[i + 1] != 'E' && data_map->line[i + 1] != ' ')
			|| (data_map->line[i] == 'E' && data_map->line[i + 1] != 'A' && data_map->line[i + 1] != ' ')
			|| (data_map->line[i] == 'N' && data_map->line[i + 1] == 'O' && data_map->line[i + 2] != ' ')
			|| (data_map->line[i] == 'S' && data_map->line[i + 1] == 'O' && data_map->line[i + 2] != ' ')
			|| (data_map->line[i] == 'W' && data_map->line[i + 1] == 'E' && data_map->line[i + 2] != ' ')
			|| (data_map->line[i] == 'E' && data_map->line[i + 1] == 'A' && data_map->line[i + 2] != ' '))
		{
			close(data_map->fd);
			free(data_map->line);
			return (0);
		}
		else
		{
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
			i = 0;
			texture_nb++;
		}
	}
	return (1);
}

int	ft_open_map(char *str, t_data_map *data_map)
{
	data_map->fd = open(str, O_RDONLY);
	if (data_map->fd < 0)
	{
		close(data_map->fd);
		return (0);
	}
	data_map->line = get_next_line(data_map->fd);
	return (1);
}

int	ft_read_map(char *str, t_data_map *data_map)
{
	int	i;

	if (!ft_open_map(str, data_map))
		return (0);
	i = 0;
	while (data_map->line[0] == '\n')
	{
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
	}
	while (data_map->line[i] == ' ')
		i++;
	if (data_map->line[i] != 'N' && data_map->line[i] != 'S'
		&& data_map->line[i] != 'W' && data_map->line[i] != 'E'
		&& data_map->line[i] != 'F' && data_map->line[i] != 'C')
	{
		close(data_map->fd);
		free(data_map->line);
		return (0);
	}
	if (data_map->line[i] == 'F' || data_map->line[i] == 'C')
		data_map->texture_color = true;
	else
		data_map->texture_color = false;
	return (1);
}
