#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) { *this = copy;}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream _db;
	std::string line;
	_db.open("data.csv");
	if (_db.is_open())
	{
		getline (_db,line);
		while ( getline (_db,line) )
			_database.push_back(std::make_pair(line.substr(0, line.find(",")), std::stod(line.substr(line.find(",") + 1, line.find("\n")))));
		// for (iterator it = _database.begin(); it != _database.end(); it++) {
		// 	std::cout << it->first << " : " << it->second << std::endl; 
		// }
    	_db.close();
  	}
	_db.open(filename);
	if (_db.is_open())
	{
		getline (_db,line);
		while ( getline (_db,line) ) {
			std::string tmp = line.substr(line.find("|") + 1, line.find("\n"));
			_input_file.push_back(std::make_pair(line.substr(0, line.find("|") - 1), std::atof(tmp.c_str())));
		}
		// for (iterator it = _input_file.begin(); it != _input_file.end(); it++) {
		// 	std::cout << it->first << " : " << it->second << std::endl; 
		// }
    	_db.close();
  	}
	for(iterator it = _database.begin(); it != _database.end(); it++) {
		for (iterator it2 = _input_file.begin(); it2 != _input_file.end(); it2++) {
			if (it2->first == it->first) {
				std::cout << it2->first << " => " << it2->second << " = " << it2->second * it->second << std::endl;
			}
		}
	}
}