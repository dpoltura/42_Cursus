# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:02:00 by dpoltura          #+#    #+#              #
#    Updated: 2024/02/13 23:18:04 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc

CFLAGS= -Wall -Werror -Wextra

SRC=	ft_printf.c \
	ft_format.c \
	ft_print_s.c \
	ft_print_c.c \
	ft_print_p.c \
	ft_putnbr_x.c \
	ft_putnbr_base_fd.c \
	ft_strlen.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_numlen.c

OBJ= $(SRC:%.c=%.o)

NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
