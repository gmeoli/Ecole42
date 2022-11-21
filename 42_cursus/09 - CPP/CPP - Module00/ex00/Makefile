# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 19:34:54 by gmeoli            #+#    #+#              #
#    Updated: 2022/11/21 18:16:45 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRCS = megaphone.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
		c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
		rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re