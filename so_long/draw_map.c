/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:43:54 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:49:54 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	fd_map_error(data);
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		while (data->line[data->i] == '1')
			put_obey(data);
		if (data->line[data->i] == 'C')
			put_bomb(data);
		else if (data->line[data->i] == 'P')
			put_char(data);
		else if (data->line[data->i] == 'E')
			put_exit(data);
		else if (data->line[data->i] == '\n')
			new_line(data);
		else if (data->line[data->i] == 'E' || data->line[data->i] == '0'
			|| data->line[data->i] == 'P')
		{
			data->x += 32;
			data->i += 1;
		}
		else
			break ;
	}
	free(data->line);
	close(data->fd);
}
