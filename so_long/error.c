/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:45:13 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:50:10 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	not_rectangular(char **map, t_data *data)
{
	free_map(map);
	ft_printf("map not rectangular: ");
	error(data);
}

void	not_surrounded(char **map, t_data *data)
{
	free_map(map);
	ft_printf("map not surrounded by wall: ");
	error(data);
}

void	not_contain_epc(char **map, t_data *data)
{
	free_map(map);
	ft_printf("map not contain correct number of 'E', 'P', 'C': ");
	error(data);
}

void	fd_map_error(t_data *data)
{
	data->fd = open(data->map, O_RDONLY);
	if (!data->fd || data->fd == -1)
	{
		perror(data->map);
		free(data->map);
		free(data->path);
		exit(0);
	}
}

void	error(t_data *data)
{
	ft_printf("Error\n");
	close_window(data);
}
