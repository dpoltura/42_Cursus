/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:48:23 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/13 23:48:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_data *data)
{
	int	y;

	y = 0;
	while (data->tab[y])
	{
		free(data->tab[y]);
		y++;
	}
	free(data->tab);
}

int	close_window(t_data *data)
{
	if (data->mlx && data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data->path);
	free(data->map);
	free_tab(data);
	exit(0);
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}
