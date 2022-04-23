# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:54:45 by gmeoli            #+#    #+#              #
#    Updated: 2022/04/23 16:04:42 by gmeoli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
						ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c  \
							ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
OBJS = $(SRCS:.c=.o)
P_OBJ = printf/ft_utilityp.o printf/ft_printf.o printf/ft_decimal.o printf/ft_hexa_maiu.o \
		printf/ft_hexa_min.o printf/ft_pointer.o printf/ft_putstr.o printf/ft_unsint.o
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS = $(BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
G_OBJ = get_next_line.o get_next_line_utils.o
G_FLAG = -D BUFFER_SIZE=1

$(NAME):
		make -C printf
		gcc -c -I $(FLAGS) $(SRCS) $(GNL) $(G_FLAG) $(PRINTF) $(PRINTF_OBJ)
		ar rc $(NAME) $(OBJS) $(P_OBJ) $(G_OBJ) $(PRINTF_OBJ)
		ranlib $(NAME)

bonus:
		gcc -c -I $(HDRS) $(FLAGS) $(BONUS)
		ar rc $(NAME) $(BONUS_OBJS)
		ranlib $(NAME)

all:        $(NAME)

clean:      
			rm -f $(OBJS) $(BONUS_OBJS) $(G_OBJ) $(PRINTF_OBJ)

fclean:     clean
			rm -f $(NAME)
			make fclean -C printf

re:         fclean all

.PHONY:     all clean fclean re bonus
