#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class BitcoinExchange
{
	private:
		std::vector<std::pair<std::string, float> >	_input_file;
		std::vector<std::pair<std::string, float> >	_database;
		typedef std::vector<std::pair<std::string, float> >::iterator	iterator;

		std::vector<std::pair<std::string, float> >	getVectorInput() const;
		std::vector<std::pair<std::string, float> >	getVectorDatabase() const;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &crhs);
		~BitcoinExchange();

		BitcoinExchange(const std::string &filename);
		void	setVectorInput();
		void	setVectorDatabase();
};
