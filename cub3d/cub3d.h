/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:29 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/24 14:05:53 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

/* structs */
typedef struct s_data_map
{
	int	fd;
	char	*line;
	bool 	texture_color;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color;
	char	*ceiling_color;
	char	**map;
}	t_data_map;

/* parse_map.c */
int	check_map_char(t_data_map *data_map);
int	not_double_player(t_data_map *data_map);
int	map_is_well_spaced(t_data_map *data_map);
int	map_is_closed(t_data_map *data_map);
int	map_exist(char *str, t_data_map *data_map);

/* init_color.c */
void	init_color(char *str, t_data_map *data_map);

/* init_texture.c */
void	init_texture(char *str, t_data_map *data_map);

/* parse.c */
int	check_color(t_data_map *data_map);
int	check_texture(t_data_map *data_map);
int	ft_open_map(char *str, t_data_map *data_map);
int	ft_read_map(char *str, t_data_map *data_map);

/* utils.c */
int		map_is_not_cub(char *str);
int		ft_error(char *str, t_data_map *data_map);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);

#endif
