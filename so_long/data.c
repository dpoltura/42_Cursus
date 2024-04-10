/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:45:27 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:49:16 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_width(t_data *data)
{
	int	width;
	int	i;

	fd_map_error(data);
	data->tab = ft_calloc(sizeof(char *), 100);
	data->tab[0] = get_next_line(data->fd);
	i = 0;
	while (data->tab[0][i] != '\n')
		i++;
	width = i * 32;
	data->window_width = width;
	i = 0;
	while (data->tab[i])
	{
		data->tab[i + 1] = get_next_line(data->fd);
		i++;
	}
	close(data->fd);
}

void	window_height(t_data *data)
{
	int	height;

	fd_map_error(data);
	data->line = get_next_line(data->fd);
	height = 0;
	while (data->line)
	{
		height += 32;
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	data->window_height = height;
	free(data->line);
	close(data->fd);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->window_width = 0;
	data->window_height = 0;
	data->image = NULL;
	data->image_address = NULL;
	data->image_width = 0;
	data->image_height = 0;
	data->x = 0;
	data->y = 0;
	data->char_x = 0;
	data->char_y = 0;
	data->tab = NULL;
	data->moves = 0;
	data->i = 0;
	data->items = 0;
	data->count_items = 0;
	data->epc[0] = 0;
	data->epc[1] = 0;
	data->epc[2] = 0;
}
