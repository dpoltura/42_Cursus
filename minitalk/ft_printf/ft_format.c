/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:12:34 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 16:27:06 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, int j, va_list args, va_list tmp)
{
	if (*(format) == 's')
		j = ft_print_s(va_arg(tmp, char *), va_arg(args, char *), j);
	else if (*(format) == 'd')
		j += ft_putnbr_fd(va_arg(args, int), 1);
	else if (*(format) == 'c')
		j = ft_print_c(va_arg(args, int), j);
	else if (*(format) == 'p')
	{
		va_copy(tmp, args);
		j = ft_print_p(va_arg(tmp, long), j, va_arg(args, long));
	}
	else if (*(format) == 'i')
		j += ft_putnbr_base_fd(va_arg(args, int), "0123456789", 1);
	else if (*(format) == 'u')
		j += ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789", 1);
	else if (*(format) == 'x')
		j += ft_putnbr_x(va_arg(args, int), "0123456789abcdef", 1);
	else if (*(format) == 'X')
		j += ft_putnbr_x(va_arg(args, int), "0123456789ABCDEF", 1);
	else if (*(format) == '%')
		j += ft_putchar_fd('%', 1);
	return (j);
}
