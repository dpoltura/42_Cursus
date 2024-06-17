/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:48:09 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/17 13:33:52 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_read_map(char *str, t_data_map *data_map)
{
	int	i;

	data_map->fd = open(str, O_RDONLY);
	if (data_map->fd < 0)
	{
		close(data_map->fd);
		return (0);
	}
	data_map->line = get_next_line(data_map->fd);
	i = 0;
	while (data_map->line[i] != 'N' && data_map->line[i] != 'S'
			&& data_map->line[i] != 'W' && data_map->line[i] != 'E')
	{
		free(data_map->line);
		data_map->line = get_next_line(data_map->fd);
		while (data_map->line[i] == ' ')
			i++;
	}
	printf("%s\n", data_map->line);
	close(data_map->fd);
	return (1);
}
