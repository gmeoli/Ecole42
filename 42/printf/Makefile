# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 12:35:51 by gmeoli            #+#    #+#              #
#    Updated: 2022/01/22 22:58:50 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRCS =	*.c
OBJS =	$(SRCS:.c=.o)
FLAGS =	-Wall -Wextra -Werror
LIBFT =	libft.a

$(NAME):
		make -C libft
		cp libft/libft.a $(NAME)
		gcc -c $(FLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: 	$(NAME)

clean:	
		rm -f $(OBJS)
	
fclean:	clean
		rm -f $(NAME) $(LIBFT)
		make fclean -C libft
	
re:		fclean all

.PHONY: all clean fclean re
