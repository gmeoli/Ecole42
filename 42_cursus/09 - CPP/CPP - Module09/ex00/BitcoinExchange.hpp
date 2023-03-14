#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class BitcoinExchange
{
	private:
		std::vector<BitcoinPrice> m_data;

		struct BitcoinPrice {
			std::string	date;
			double		value;
		}
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &crhs);
		~BitcoinExchange();

		BitcoinExchange(const std::string &filename);
		double	getValue(const std::string &date) const;
    	void	setValue(const std::string &date, double value);
};
