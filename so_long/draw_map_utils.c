/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:29:31 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:49:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_obey(t_data *data)
{
	data->image_address = mlx_xpm_file_to_image(data->mlx, "src/obey.xpm",
			&data->image_width, &data->image_height);
	mlx_put_image_to_window(data->mlx, data->window, data->image_address,
		data->x, data->y);
	mlx_destroy_image(data->mlx, data->image_address);
	data->x += 32;
	data->i += 1;
}

void	put_bomb(t_data *data)
{
	data->image_address = mlx_xpm_file_to_image(data->mlx, "src/bomb.xpm",
			&data->image_width, &data->image_height);
	mlx_put_image_to_window(data->mlx, data->window, data->image_address,
		data->x, data->y);
	mlx_destroy_image(data->mlx, data->image_address);
	data->x += 32;
	data->i += 1;
}

void	put_char(t_data *data)
{
	data->image_address = mlx_xpm_file_to_image(data->mlx, "src/char.xpm",
			&data->image_width, &data->image_height);
	mlx_put_image_to_window(data->mlx, data->window, data->image_address,
		data->x, data->y);
	mlx_destroy_image(data->mlx, data->image_address);
	data->char_x = data->x;
	data->char_y = data->y;
	data->x += 32;
	data->i += 1;
}

void	put_exit(t_data *data)
{
	data->image_address = mlx_xpm_file_to_image(data->mlx, "src/exit.xpm",
			&data->image_width, &data->image_height);
	mlx_put_image_to_window(data->mlx, data->window, data->image_address,
		data->x, data->y);
	mlx_destroy_image(data->mlx, data->image_address);
	data->x += 32;
	data->i += 1;
}

void	new_line(t_data *data)
{
	data->y += 32;
	free(data->line);
	data->line = get_next_line(data->fd);
	data->i = 0;
	data->x = 0;
}
