/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/24 14:07:09 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data_map	*data_map;

	data_map = NULL;
	if (argc < 2)
		return (ft_error("Too few arguments\n", data_map));
	if (argc > 2)
		return (ft_error("Too many arguments\n", data_map));
	if (map_is_not_cub(argv[1]))
		return (ft_error("Map is not .cub\n", data_map));
	data_map = malloc(sizeof(t_data_map));
	if (!data_map)
		return (ft_error("Can't allocate memory\n", data_map));
	if (!ft_read_map(argv[1], data_map))
	{
		free(data_map);
		return (ft_error("Can't read map\n", data_map));
	}
	if (!data_map->texture_color)
	{
		if (!check_texture(data_map))
		{
			free(data_map);
			return (ft_error("Can't read texture\n", data_map));
		}
		if (!check_color(data_map))
		{
			free(data_map);
			return (ft_error("Can't read color\n", data_map));
		}
	}
	if (data_map->texture_color)
	{
		if (!check_color(data_map))
		{
			free(data_map);
			return (ft_error("Can't read color\n", data_map));
		}
		if (!check_texture(data_map))
		{
			free(data_map);
			return (ft_error("Can't read texture\n", data_map));
		}
	}
	init_texture(argv[1], data_map);
	init_color(argv[1], data_map);

	/* print texture & color */
	printf("%s\n", data_map->no_texture);
	printf("%s\n", data_map->so_texture);
	printf("%s\n", data_map->we_texture);
	printf("%s\n", data_map->ea_texture);
	printf("%s\n", data_map->floor_color);
	printf("%s\n", data_map->ceiling_color);

	if (!map_exist(argv[1], data_map) || !map_is_closed(data_map)
		|| !map_is_well_spaced(data_map) || !check_map_char(data_map))
		return (ft_error("Invalid map\n", data_map));
	if (!not_double_player(data_map))
		return (ft_error("Not one player\n", data_map));
	
	/* print map */
	int i = 0;
	while (data_map->map[i])
	{
		printf("%s\n", data_map->map[i]);
		i++;
	}
	
	/* free */
	close(data_map->fd);
	free(data_map->line);
	free(data_map->no_texture);
	free(data_map->so_texture);
	free(data_map->we_texture);
	free(data_map->ea_texture);
	free(data_map->floor_color);
	free(data_map->ceiling_color);
	i = 0;
	while (data_map->map[i])
	{
		free(data_map->map[i]);
		i++;
	}
	free(data_map);
	return (0);
}
