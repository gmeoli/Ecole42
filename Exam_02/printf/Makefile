# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 12:35:51 by gmeoli            #+#    #+#              #
#    Updated: 2022/03/03 09:10:18 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = gcc
LIBC = ar rc
CFLAGS  += -Wall -Werror -Wextra

SRC =	ft_printf.c 
				
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
