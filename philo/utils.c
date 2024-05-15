/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:20:37 by dpoltura          #+#    #+#             */
/*   Updated: 2024/05/14 15:08:03 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     ft_atoi(const char *nptr)
{
    int     i;
    int     j;
    int     k;
 
    i = 0;
    j = 1;
    k = 0;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
        i++;
    if (nptr[i] < '0' || nptr[i] > '9')
        return (0);
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
            k = k * 10;
            k += nptr[i] - '0';
            i++;
    }
    return (k * j);
}
