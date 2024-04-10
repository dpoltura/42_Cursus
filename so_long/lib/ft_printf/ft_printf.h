/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:59:26 by dpoltura          #+#    #+#             */
/*   Updated: 2023/11/24 09:46:32 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_format(const char *format, int j, va_list args, va_list tmp);
int		ft_putnbr_x(unsigned int n, char *base, int fd);
int		ft_print_s(char *tmp, char *args, int j);
int		ft_print_c(int args, int j);
int		ft_print_p(long tmp, int j, long args);
int		ft_putnbr_base_fd(long n, char *base, int fd);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_numlen(long n);

#endif
