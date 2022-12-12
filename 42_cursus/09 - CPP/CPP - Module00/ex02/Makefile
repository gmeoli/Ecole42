NAME = report_accounts
SOURCES = tests.cpp Account.cpp
OBJECT = $(SOURCE:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	@c++ $(SOURCES) $(FLAGS) $(OBJECT) -o $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re