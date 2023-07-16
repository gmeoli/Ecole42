#include "Harl.hpp"

// PRIVATE
void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

// PUBLIC
void Harl::complain ( std::string str ) {
	std::unordered_map<std::string, int> level;
	level.insert(std::pair<std::string, int>("DEBUG", 1));
	level.insert(std::pair<std::string, int>("INFO", 2));
	level.insert(std::pair<std::string, int>("WARNING", 3));
	level.insert(std::pair<std::string, int>("ERROR", 4));

	switch (level[str]) {
		case 1:
			this->debug();
		case 2:
			this->info();
		case 3:
			this->warning();
		case 4:
			this->error();
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
