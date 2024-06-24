/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:48:25 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/24 11:32:12 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_c_color(char *str, int i, t_data_map *data_map)
{
	if (str && str[i] == 'C')
	{
		if (data_map->ceiling_color)
		{
			ft_error("Double in color\n");
			return (0);
		}
		i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			data_map->ceiling_color = ft_strdup(&str[i]);
		else
		{
			ft_error("Can't read color\n");
			return (0);
		}
	}
	return (1);
}

static int	is_f_color(char *str, int i, t_data_map *data_map)
{
	if (str && str[i] == 'F')
	{
		if (data_map->floor_color)
		{
			ft_error("Double in color\n");
			return (0);
		}
		i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			data_map->floor_color = ft_strdup(&str[i]);
		else
		{
			ft_error("Can't read color\n");
			return (0);
		}
	}
	return (1);
}

void	init_color(char *str, t_data_map *data_map)
{
	int	i;

	i = 0;
	data_map->floor_color = NULL;
	data_map->ceiling_color = NULL;
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
		if (!is_f_color(data_map->line, i, data_map))
			return ;
		if (!is_c_color(data_map->line, i, data_map))
			return ;
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
		i = 0;
	}
	if (!data_map->floor_color || !data_map->ceiling_color)
		ft_error("Double in color\n");
}
