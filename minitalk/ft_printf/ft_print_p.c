/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:25:50 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 16:29:43 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(long tmp, int j, long args)
{
	if (!tmp)
		j += ft_putstr_fd("(nil)", 1);
	else
		j += ft_putstr_fd("0x", 1);
	j += ft_putnbr_base_fd(args, "0123456789abcdef", 1);
	return (j);
}
