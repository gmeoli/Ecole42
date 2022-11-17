# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 17:59:38 by gmeoli            #+#    #+#              #
#    Updated: 2022/11/17 20:16:35 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = *.c
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -L/usr/include -lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include/readline

$(NAME):
		make -C libft
		gcc $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT) -ledit

clean:
		rm -rf $(NAME)

fclean:	clean
		make fclean -C libft

all: 	$(NAME)

re:		fclean all