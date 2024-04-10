# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:59:26 by dpoltura          #+#    #+#              #
#    Updated: 2024/02/13 23:53:51 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC =	main.c \
		key_hook.c \
		draw_map.c \
		draw_map_utils.c \
		items.c \
		data.c \
		close_and_free.c \
		check.c \
		floodfill.c \
		error.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
INCLUDE = -L lib/minilibx-linux -lmlx -lX11 -lXext -L lib/libft -lft -L lib/ft_printf -lftprintf 
LIBFT = libft.a
FT_PRINTF = libftprintf.a
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/libft
	$(MAKE) -C lib/ft_printf
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re