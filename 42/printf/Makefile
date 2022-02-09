# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 12:35:51 by gmeoli            #+#    #+#              #
#    Updated: 2022/02/09 18:48:22 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = gcc
LIBC = ar rc
CFLAGS  += -Wall -Werror -Wextra

SRC =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_pointer.c \
		ft_hexa.c \
		ft_utility1.c \
		
		
OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}
	
all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f *~ $(NAME)

re: fclean all
