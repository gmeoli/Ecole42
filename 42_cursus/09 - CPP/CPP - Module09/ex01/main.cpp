#include "RPN.hpp"

int main(int ac, char **av) {

	(void)ac;
	std::string	str(av[1]);
	try {
		if (!av[1] || av[2])
			throw std::runtime_error("Error\nArgument not valid");
		if (str.find_first_not_of("0123456789-+/* ") != std::string::npos)
			throw std::runtime_error("Error");
		RPN rpn(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
