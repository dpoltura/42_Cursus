/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:57:33 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:54:14 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		window_width;
	int		window_height;
	void	*image;
	char	*image_address;
	int		image_width;
	int		image_height;
	int		x;
	int		y;
	int		char_x;
	int		char_y;
	char	**tab;
	int		moves;
	int		i;
	int		fd;
	char	*line;
	char	*map;
	char	*path;
	int		items;
	int		count_items;
	int		epc[3];
}			t_data;

void		key_w(t_data *data);
void		key_a(t_data *data);
void		key_s(t_data *data);
void		key_d(t_data *data);
int			key_hook(int keycode, t_data *data);
int			close_window(t_data *data);
void		put_obey(t_data *data);
void		put_bomb(t_data *data);
void		put_char(t_data *data);
void		put_exit(t_data *data);
void		new_line(t_data *data);
void		count_items(t_data *data);
void		items(t_data *data);
void		count_items(t_data *data);
void		draw_map(t_data *data);
void		window_width(t_data *data);
void		window_height(t_data *data);
void		init_data(t_data *data);
void		free_tab(t_data *data);
int			close_window(t_data *data);
void		fd_map_error(t_data *data);
void		error(t_data *data);
void		free_map(char **map);
void		check_rectangle(char **map, t_data *data);
void		check_wall(char **map, t_data *data);
void		check_epc(char **map, t_data *data);
void		check_characters(char **map, t_data *data);
void		check_all(t_data *data);
void		char_pos(t_data *data);
void		floodfill(int x, int y, char **map, t_data *data);
void		check_after_floodfill(char **map, t_data *data);
char		**clone_map(t_data *data);
void		not_rectangular(char **map, t_data *data);
void		not_surrounded(char **map, t_data *data);
void		not_contain_epc(char **map, t_data *data);

#endif