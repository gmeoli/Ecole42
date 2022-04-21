# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 19:25:21 by gmeoli            #+#    #+#              #
#    Updated: 2022/03/16 13:43:07 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT = ft_client.c
SRCS_SERVER = ft_server.c
LIBFT = ./libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: client server

bonus: client server

$(LIBFT):
	$(MAKE) -C ./libft

client: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRCS_CLIENT) -o client

server: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRCS_SERVER) -o server

clean:
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f server client
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus
