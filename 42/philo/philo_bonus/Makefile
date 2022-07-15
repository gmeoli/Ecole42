# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 13:16:44 by gmeoli            #+#    #+#              #
#    Updated: 2022/07/15 17:15:39 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRCS = *.c

FLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=address -g3
$(NAME):
	gcc $(SRCS) $(FLAGS) -o $(NAME)

all: $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all

.PHONY: all clean fclean re