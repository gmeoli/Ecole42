#include "RPN.hpp"

int main(int ac, char **av) {

	(void)ac;
	try {
		if (!av[1] || av[2])
			throw std::runtime_error("Error\nArgument not valid");
		RPN rpn(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
