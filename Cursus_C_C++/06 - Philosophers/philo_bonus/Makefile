# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 13:16:44 by gmeoli            #+#    #+#              #
#    Updated: 2022/07/18 19:04:57 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRCS = *.c

FLAGS = -Wall -Wextra -Werror -pthread
$(NAME):
	gcc $(SRCS) $(FLAGS) -o $(NAME)

all: $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all

.PHONY: all clean fclean re