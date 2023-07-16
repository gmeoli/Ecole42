#include "PmergeMe.hpp"

int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Error\nNo sequence provided" << std::endl;
		return 1;
	}
	try {
		PmergeMe	ANTANI(ac, av);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}