# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 19:21:06 by lsylvana          #+#    #+#              #
#    Updated: 2020/02/29 01:32:54 by sbrynn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -O3

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HDR = $(LIBFT_DIR)

MINILIBX_DIR = ./minilibx_macos/
MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_HDR = $(MINILIBX_DIR)

LIBS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_HDR) -I$(MINILIBX_HDR)

HDRS = fdf.h
SRC = main.c read.c map_helper.c line_writer.c drawer.c map_corrector.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) $(OBJ) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) $(INCLUDES) -c $<

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -sC $(MINILIBX_DIR)

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MINILIBX_DIR) clean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(MINILIBX)
	/bin/rm -f $(NAME)

re: fclean all
