/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:05:21 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/17 12:27:16 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_is_not_cub(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	return (0);
}

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_error("Too few arguments\n"));
	if (argc > 2)
		return (ft_error("Too many arguments\n"));
	if (map_is_not_cub(argv[1]))
		return (ft_error("Map is not .cub\n"));
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Can't open map\n"));
	
	return (0);
}
