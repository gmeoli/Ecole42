# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 19:34:54 by gmeoli            #+#    #+#              #
#    Updated: 2022/11/21 16:03:53 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRCS = megaphone.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98


$(NAME):
		c++ $(FLAGS) $(SRCS) -o $(NAME)

clean: rm -fr $(NAME)

fclean: clean

all:	$(NAME)

re: fclean all

.PHONY: all clean fclean re