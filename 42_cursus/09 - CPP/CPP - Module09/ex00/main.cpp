#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	(void)ac;
	try {
		if (av[2])
			throw std::runtime_error("Error\nArgument not valid");
		BitcoinExchange	btc("data.csv");
		btc.exchange(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
