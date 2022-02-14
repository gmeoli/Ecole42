# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 19:25:21 by gmeoli            #+#    #+#              #
#    Updated: 2022/02/14 19:54:15 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = gcc
LIBC = ar rc
CFLAGS  += -Wall -Werror -Wextra

SRC =	ft_client.c \
		ft_server.c \
	

OBJS = $(SRC:.c=.o)

NAME = minitalk.a

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
