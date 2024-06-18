/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:14:54 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/18 13:13:48 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	is_ea_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'E')
	{
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->ea_texture = ft_strdup(&str[i]);
		else
			ft_error("Can't read texture\n");
	}
}

static void	is_we_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'W')
	{
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->we_texture = ft_strdup(&str[i]);
		else
			ft_error("Can't read texture\n");
	}
}

static void	is_so_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'S')
	{
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->so_texture = ft_strdup(&str[i]);
		else
			ft_error("Can't read texture\n");
	}
}

static void	is_no_texture(char *str, int i, t_data_map *data_map)
{
	if (str[i] == 'N')
	{
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->no_texture = ft_strdup(&str[i]);
		else
			ft_error("Can't read texture\n");
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
		if (!data_map->no_texture)
			is_no_texture(data_map->line, i, data_map);
		if (!data_map->so_texture)
			is_so_texture(data_map->line, i, data_map);
		if (!data_map->we_texture)
			is_we_texture(data_map->line, i, data_map);
		if (!data_map->ea_texture)
			is_ea_texture(data_map->line, i, data_map);
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
		i = 0;
	}
	if (!data_map->no_texture || !data_map->so_texture
		|| !data_map->we_texture || !data_map->ea_texture)
		ft_error("Double in texture\n");
}
