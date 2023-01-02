# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 15:02:44 by ebondi            #+#    #+#              #
#    Updated: 2022/12/10 21:34:43 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Werror -Wextra -l mlx -framework openGL -framework AppKit
OBJS = main.c utils.c map.c
LIBFT = libft/libft.a 
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_FLAGS = -D BUFFER_SIZE=42

$(NAME):$(OBJS)
		@make -C libft
		@gcc $(FLAGS) $(OBJS) -o $(NAME) $(GNL) $(GNL_FLAGS) $(LIBFT)
		@printf "\033[1;35mCub3D compiled!!\e[0m\n"

all: $(NAME)

bonus: $(NAME)

clean:
	@make clean -C libft

fclean:
	@rm -f $(NAME)
	@make fclean -C libft
	@printf "\033[1;91mRemoving objects...\n"

re: all bonus clean fclean relibft 

relibft:
		@make fclean -C libft
		@make -C libft
vai: re
	@./$(NAME)

leaks:
	@leaks --atExit -- ./$(NAME)

.PHONY:	all clean fclean re bonus vai leaks relibft