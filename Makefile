# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/12 11:32:29 by elwilks           #+#    #+#              #
#    Updated: 2026/03/14 18:45:47 by elwilks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -O2

MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

SRCS    = 	src/main.c \
		src/mandelbrot.c \
		src/julia.c \
		src/render.c \
		src/hooks.c \
		src/utils.c
OBJS    = $(SRCS:.c=.o)

INCLUDES = -I$(MLX_DIR)/include -Iinclude
LIBS     = $(MLX_LIB) -lglfw -lm -ldl -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
