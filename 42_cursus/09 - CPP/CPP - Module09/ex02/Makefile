NAME 	=	PmergeMe
CC		=	c++
FLAGS	=	-Wall -Werror -Wextra -std=c++98
SRCS	=	main.cpp \
			PmergeMe.cpp
OBJS	=	${SRCS:.cpp=.o}

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
	@ rm -f $(OBJS)

fclean	:	clean
	@ rm -f $(NAME)

re	:	clean all

.PHONY	:	all clean fclean re