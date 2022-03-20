# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 17:18:27 by gmeoli            #+#    #+#              #
#    Updated: 2022/03/18 16:13:20 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft/libft.a

SRCSFLS = so_long.c

SRCS = $(addprefix src/, $(SRCSFLS))

OBJS = $(SRCS:.c=.o)

HDRS = so_long.h

FLAGS = -Wall -Werror -Wextra

COMPILER = -l mlx -framework openGL -framework AppKit

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(LIBFT)
	gcc $(FLAGS) $(SRCS) $(LIBFT) $(COMPILER) -o $(NAME)

bonus: all

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus
