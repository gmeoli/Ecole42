#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::vector<std::pair<std::string, double> >	_exchangeRate;
	public:
		typedef std::vector<std::pair<std::string, double> >::iterator	iterator;

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &crhs);
		~BitcoinExchange();

		BitcoinExchange(char const *file_input);
		int		checkFormat(std::string	const &line, std::string const &value);
		void	exchange(char const *file_input);
};
