# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:03:43 by dpoltura          #+#    #+#              #
#    Updated: 2024/06/18 14:14:44 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror -g

SRCS =  main.c \
		utils.c \
		parse.c \
		init_texture.c \
		init_color.c \
		parse_map.c

GNL_SRCS =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

GNL_OBJS = $(GNL_SRCS:%.c=%.o)

NAME = cub3d

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	$(CC) $(OBJS) $(GNL_OBJS) -o $(NAME)

clean:
	rm $(OBJS) $(GNL_OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
