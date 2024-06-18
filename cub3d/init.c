/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:14:54 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/18 11:40:23 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_ea_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'E')
	{
		while (str[i] && str[i] != '.')
			i++;
		if (str[i] == '.')
			data_map->ea_texture = ft_strdup(&str[i]);
	}
}

void	is_we_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'W')
	{
		while (str[i] && str[i] != '.')
			i++;
		if (str[i] == '.')
			data_map->we_texture = ft_strdup(&str[i]);
	}
}

void	is_so_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'S')
	{
		while (str[i] && str[i] != '.')
			i++;
		if (str[i] == '.')
			data_map->so_texture = ft_strdup(&str[i]);
	}
}

void	is_no_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'N')
	{
		while (str[i] && str[i] != '.')
			i++;
		if (str[i] == '.')
			data_map->no_texture = ft_strdup(&str[i]);
	}
}

void	init_texture(char *str, t_data_map *data_map)
{
	int	i;

	i = 0;
	while (data_map->line)
	{
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
	}
	close(data_map->fd);
	ft_open_map(str, data_map);
	while (data_map->line)
	{
		while (data_map->line[0] == '\n')
		{
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
		}
		while (data_map->line[i] == ' ')
			i++;
		is_no_texture(data_map->line, i, data_map);
		is_so_texture(data_map->line, i, data_map);
		is_we_texture(data_map->line, i, data_map);
		is_ea_texture(data_map->line, i, data_map);
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
		i = 0;
	}
}
