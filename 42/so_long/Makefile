# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 17:18:27 by gmeoli            #+#    #+#              #
#    Updated: 2022/04/12 12:26:04 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c \
		read_map.c \
		check_map.c \
		open_images.c \
		utility.c \
		print_map.c \
		movement.c \
		utility2.c
		
FLAGS = -Wall -Werror -Wextra 
LIBFT = libft/libft.a
MLX_FLAG = -l mlx -framework openGL -framework AppKit

$(NAME):
			make re  -C libft
			gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBFT) $(MLX_FLAG)
all: $(NAME)
clean:
			rm -f $(NAME)
fclean: clean
			make fclean -C libft
re: fclean all

.PHONY:	all clean fclean re
