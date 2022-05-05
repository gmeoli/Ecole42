# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 10:40:51 by gmeoli            #+#    #+#              #
#    Updated: 2022/05/03 10:57:30 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c \
		operations1.c \
		operations2.c \
		operations3.c \
		utility.c \
		error.c \
		renumber_stack.c \
		push_swap1.c \
		push_swap2.c \
		push_swap3.c

FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

$(NAME):
		make re -C libft
		gcc $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT)

all: $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C libft
re: fclean all

.PHONY: all clean fclean re
