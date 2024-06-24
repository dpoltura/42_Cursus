/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:14:54 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/24 14:08:32 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_ea_texture(char *str, int i, t_data_map *data_map)
{
	if (str && str[i] == 'E')
	{
		if (data_map->ea_texture)
		{
			ft_error("Double in texture\n", data_map);
			return (0);
		}
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->ea_texture = ft_strdup(&str[i]);
		else
		{
			ft_error("Can't read texture\n", data_map);
			return (0);
		}
	}
	return (1);
}

static int	is_we_texture(char *str, int i, t_data_map *data_map)
{
	if (str && str[i] == 'W')
	{
		if (data_map->we_texture)
		{
			ft_error("Double in texture\n", data_map);
			return (0);
		}
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->we_texture = ft_strdup(&str[i]);
		else
		{
			ft_error("Can't read texture\n", data_map);
			return (0);
		}
	}
	return (1);
}

static int	is_so_texture(char *str, int i, t_data_map *data_map)
{
	if (str && str[i] == 'S')
	{
		if (data_map->so_texture)
		{
			ft_error("Double in texture\n", data_map);
			return (0);
		}
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->so_texture = ft_strdup(&str[i]);
		else
		{
			ft_error("Can't read texture\n", data_map);
			return (0);
		}
	}
	return (1);
}

static int	is_no_texture(char *str, int i, t_data_map *data_map)
{
	if (str && str[i] == 'N')
	{
		if (data_map->no_texture)
		{
			ft_error("Double in texture\n", data_map);
			return (0);
		}
		i += 2;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '.' && str[i + 1] == '/')
			data_map->no_texture = ft_strdup(&str[i]);
		else
		{
			ft_error("Can't read texture\n", data_map);
			return (0);
		}
	}
	return (1);
}

void	init_texture(char *str, t_data_map *data_map)
{
	int	i;

	i = 0;
	data_map->no_texture = NULL;
	data_map->so_texture = NULL;
	data_map->we_texture = NULL;
	data_map->ea_texture = NULL;
	while (data_map->line)
	{
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
	}
	close(data_map->fd);
	ft_open_map(str, data_map);
	while (data_map->line)
	{
		while (data_map->line && data_map->line[0] == '\n')
		{
			free(data_map->line);
			data_map->line = get_next_line(data_map->fd);
		}
		while (data_map->line && data_map->line[i] == ' ')
			i++;
		if (!is_no_texture(data_map->line, i, data_map))
			return ;
		if (!is_so_texture(data_map->line, i, data_map))
			return ;
		if (!is_we_texture(data_map->line, i, data_map))
			return ;
		if (!is_ea_texture(data_map->line, i, data_map))
			return ;
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
		i = 0;
	}
	if (!data_map->no_texture || !data_map->so_texture
		|| !data_map->we_texture || !data_map->ea_texture)
		ft_error("Double in texture\n", data_map);
}
