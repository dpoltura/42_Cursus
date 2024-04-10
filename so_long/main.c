/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:41 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:52:35 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	data.path = ft_strjoin(argv[1], ".ber");
	data.map = ft_strjoin("map/", data.path);
	init_data(&data);
	window_width(&data);
	window_height(&data);
	check_all(&data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, data.window_width,
			data.window_height, "so_long");
	draw_map(&data);
	items(&data);
	mlx_key_hook(data.window, key_hook, &data);
	mlx_hook(data.window, 17, 1L << 17, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
