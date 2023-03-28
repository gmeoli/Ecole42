#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	throw std::runtime_error("Error: could not open file.");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	this->_exchangeRate = copy._exchangeRate;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this == &rhs)
		return *this;
	this->_exchangeRate = rhs._exchangeRate;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	this->_exchangeRate.clear();
}

BitcoinExchange::BitcoinExchange(char const *file_input)
{
	std::ifstream	db(file_input);
	std::string		line, date;
	char			sep;
	double			value;
	
	if (!db.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::getline(db, line);
	if (line.length() != 18 || line.compare(0, 4, "date") || line.compare(5, 13, "exchange_rate")) {
		db.close();
		throw std::runtime_error("Error: bad file format.");
	}

	sep = line.at(4);

	while(std::getline(db, date, sep)) {
		std::getline(db, line);
		std::replace(line.begin(), line.end(), ',', '.');
		std::istringstream(line) >> value;
		if (checkFormat(date, line) || (value < 0.0 || value >= 2147483647)) {
			_exchangeRate.clear();
			db.close();
			throw std::runtime_error("Error: bad file format.");
		}
		_exchangeRate.push_back(std::make_pair(date, value));
	}
	db.close();
}

int	BitcoinExchange::checkFormat(std::string const &date, std::string const &value) {
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return 1;
	
	std::string	ymd[3];
	ymd[0] = date.substr(0, 4);
	ymd[1] = date.substr(5, 2);
	ymd[2] = date.substr(8, 2);
	if (ymd[0].length() != 4 || ymd[1].length() != 2 || ymd[2].length() != 2)
		return 1;

	double	n;
	std::istringstream(ymd[0]) >> n;
	if (n <= 0 || n >= 2147483647)
		return 1;
	std::istringstream(ymd[1]) >> n;
	if (n <= 0 || n > 12)
		return 1;
	std::istringstream(ymd[2]) >> n;
	if (n <= 0 || n > 31)
		return 1;

	if (value.find_first_not_of("0123456789.-+") != std::string::npos || std::count(value.begin(), value.end(), '.') > 1)
		return 1;

	std::istringstream(value) >> n;
	if (n < 0)
		return 2;
	else if (n >= 2147483647)
		return 3;

	return 0;
}

void	BitcoinExchange::exchange(char const *file_input) {
	std::ifstream	db(file_input);
	std::string		line;
	int				ret;
	double			n;

	if (!db.is_open())
		throw std::runtime_error("Error: could not open file.");

	while (std::getline(db, line)) {
		if (line == "date | value")
			continue;

		std::string	date, value;
		if (line.length() < 13 || line.substr(10, 3) != " | ")
			ret = 1;
		else {
			date = line.substr(0, 10);
			value = line.substr(13);
			std::replace(value.begin(), value.end(), ',', '.');
			ret = checkFormat(date, value);
		}

		switch (ret) {
		case 1:
			std::cout << "Error: bad input => " << line << std::endl;
			break;
		case 2:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case 3:
			std::cout << "Error: too large a number." << std::endl;
			break;
		default:
			std::vector<std::pair<std::string, double> >::iterator it = _exchangeRate.begin();
			while (it != _exchangeRate.end() && it->first < date)
				it++;
			if (it == _exchangeRate.begin() || (it != _exchangeRate.end() && it->first != date))
				it--;
			std::istringstream(value) >> n;
			std::cout << date << " => " << n << " = " << n * it->second << std::endl;
			break;
		}
	}
}
