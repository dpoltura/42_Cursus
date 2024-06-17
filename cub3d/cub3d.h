/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:29 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/17 12:27:41 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* utils.c */
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);

/* main.c */
int	ft_error(char *str);
int	map_is_not_cub(char *str);

