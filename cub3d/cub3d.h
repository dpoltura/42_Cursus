/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:29 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/17 13:31:24 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* structs */
typedef struct s_data_map
{
	int	fd;
	char	*line;
}	t_data_map;

/* parse.c */
int	ft_read_map(char *str, t_data_map *data_map);

/* utils.c */
void	ft_putstr_fd(char *s, int fd);

/* main.c */
int	ft_error(char *str);
int	map_is_not_cub(char *str);

#endif
