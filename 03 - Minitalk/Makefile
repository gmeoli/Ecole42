# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 19:25:21 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/05 15:12:30 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME1 = server
NAME_BONUS = client_bonus
NAME_BONUS1 = server_bonus
SRC_CLIENT = ft_client.c
SRC_SERVER = ft_server.c
LIBFT = ./libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: client server

bonus: client_bonus server_bonus

$(LIBFT):
	$(MAKE) -C ./libft

client: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRC_CLIENT) -o $(NAME)

server: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRC_SERVER) -o $(NAME1)

client_bonus: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRC_CLIENT) -o $(NAME_BONUS)

server_bonus: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRC_SERVER) -o $(NAME_BONUS1)

clean:
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f server client server_bonus client_bonus
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus
