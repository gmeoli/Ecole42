# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 10:40:51 by gmeoli            #+#    #+#              #
#    Updated: 2022/06/17 19:19:30 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
SRCS = main.c \
		operations1.c \
		operations2.c \
		operations3.c \
		utility1.c \
		utility2.c \
		error.c \
		renumber_stack.c \
		lis.c \
		push_stack_b.c \
		push_swap1.c \
		push_swap2.c \
		special_condition.c

SRCS_BONUS = utility1.c \
			operations1.c \
			operations2.c \
			operations3.c \
			bonus.c \
			error.c

FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

$(NAME):
		make re -C libft
		gcc $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT)

$(BONUS): $(SRCS_BONUS)
		make re -C libft
		gcc $(FLAGS) $(SRCS_BONUS) -o $(BONUS) $(LIBFT)

all: $(NAME)
bonus: $(BONUS)
clean:
	rm -f $(NAME) $(BONUS)
fclean: clean
	make fclean -C libft
re: fclean all

.PHONY: all bonus clean fclean re
