/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/18 11:43:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_is_not_cub(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	return (0);
}

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data_map	*data_map;

	if (argc < 2)
		return (ft_error("Too few arguments\n"));
	if (argc > 2)
		return (ft_error("Too many arguments\n"));
	if (map_is_not_cub(argv[1]))
		return (ft_error("Map is not .cub\n"));
	data_map = malloc(sizeof(t_data_map));
	if (!data_map)
		return (ft_error("Can't allocate memory\n"));
	if (!ft_read_map(argv[1], data_map))
	{
		free(data_map);
		return (ft_error("Can't read map\n"));
	}
	if (!data_map->texture_color)
	{
		if (!check_texture(data_map))
		{
			free(data_map);
			return (ft_error("Can't read texture\n"));
		}
		if (!check_color(data_map))
		{
			free(data_map);
			return (ft_error("Can't read color\n"));
		}
	}
	if (data_map->texture_color)
	{
		if (!check_color(data_map))
		{
			free(data_map);
			return (ft_error("Can't read color\n"));
		}
		if (!check_texture(data_map))
		{
			free(data_map);
			return (ft_error("Can't read texture\n"));
		}
	}
	init_texture(argv[1], data_map);
	
	close(data_map->fd);
	free(data_map->line);
	free(data_map->no_texture);
	free(data_map->so_texture);
	free(data_map->we_texture);
	free(data_map->ea_texture);
	free(data_map);
	return (0);
}
