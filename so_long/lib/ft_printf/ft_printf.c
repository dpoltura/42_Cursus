/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:58:56 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/23 16:33:49 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	tmp;
	int		j;

	va_start(args, format);
	va_copy(tmp, args);
	j = 0;
	while (*format)
	{
		while (*format == '%')
		{
			format++;
			j = ft_format(format, j, args, tmp);
			format++;
		}
		if (*(format))
		{
			write(1, &(*format), 1);
			format++;
			j++;
		}
	}
	va_end(args);
	va_end(tmp);
	return (j);
}
