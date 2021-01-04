# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamual <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 13:22:36 by msamual           #+#    #+#              #
#    Updated: 2020/12/17 18:59:36 by msamual          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft minilibx

NAME = cub3D

SRCS = srcs/main.c \
		srcs/GNL/get_next_line.c \
		srcs/GNL/get_next_line_utils.c \
		srcs/parse_map.c \
		srcs/parse_info.c \
		srcs/init.c \
		srcs/check_map.c \
		srcs/put_map_in_window.c \
		srcs/key_handle.c \
		srcs/pixel_put.c \
		srcs/key_handle_arrow.c \
		srcs/init_player.c \
		srcs/vectors.c \
		srcs/put_vert_line.c \
		srcs/texture.c \
		srcs/print_tools.c

INC = includes

FLAGS = -Wall -Wextra -Werror -g

CC = gcc $(FLAGS)

OBJ = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

libft:
	make -C srcs/libft

minilibx:
	make -C srcs/minilibx

$(%.o): $(%.c)
	$(CC) -o $@ -c $^ -I$(INC)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -L . -lmlx -framework OPENGL -framework Appkit -lm -Lsrcs/libft -lft -I $(INC)

clean:
	rm -f $(OBJ)
	make -C srcs/libft/ clean
	make -C srcs/minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C srcs/libft/ fclean
	make -C srcs/minilibx/ clean

re: fclean all
