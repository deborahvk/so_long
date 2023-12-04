# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkott <dkott@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:30:10 by dkott             #+#    #+#              #
#    Updated: 2023/11/30 14:12:58 by dkott            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g3 -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext

INCL = -I -I./libft -I./minilibx

SRCS = 	./game_code/controls.c\
		./game_code/errors.c\
		./game_code/errors2.c\
		./game_code/error_fill.c\
		./game_code/check_path.c\
		./game_code/utils_errors.c\
		./game_code/graphics.c\
		./game_code/graphics2.c\
		./game_code/map.c\
		./game_code/so_long.c\
		./game_code/free.c\
		./game_code/handle.c\

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx/libmlx_Linux.a

$(NAME) : $(OBJS)
	make lib
	make mlx
	cc -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS)

all: $(NAME)

%.o: %.c
	cc $(INCL) $(CFLAGS) -o $@ -c $<

mlx:
	make -C ./minilibx/ all

lib:
	make -C ./libft/ all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean 
	make all

.PHONY : all clean fclean re
