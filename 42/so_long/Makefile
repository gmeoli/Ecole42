# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 17:18:27 by gmeoli            #+#    #+#              #
#    Updated: 2022/03/20 16:37:48 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c read_map.c
FLAG = -Wall -Werror -Wextra 
LIBFT = libft/libft.a
MLX_FLAG = -l mlx -framework openGL -framework AppKit

$(NAME):
			make re  -C libft
			gcc $(SRC) -o $(NAME) $(LIBFT) $(MLX_FLAG)
all: $(NAME)
clean:
			rm -f $(NAME)
fclean: clean
			make fclean -C libft
re: fclean all
.PHONY:	all clean fclean re
