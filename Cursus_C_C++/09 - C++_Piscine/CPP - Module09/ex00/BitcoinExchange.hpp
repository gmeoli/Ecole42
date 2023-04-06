#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_exchangeRate;
	public:
		typedef std::map<std::string, double>::iterator	iterator;

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &crhs);
		~BitcoinExchange();

		BitcoinExchange(char const *file_input);
		int		checkFormat(std::string	const &line, std::string const &value);
		void	exchange(char const *file_input);
};
