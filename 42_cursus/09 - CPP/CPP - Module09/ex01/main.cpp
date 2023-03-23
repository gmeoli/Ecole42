#include "RPN.hpp"

int main(int ac, char **av) {

	(void)ac;
	try {
		RPN rpn(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
