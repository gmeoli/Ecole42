#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	(void)ac;
	try {
		BitcoinExchange	btc("data.csv");
		btc.exchange(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
