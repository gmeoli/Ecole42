#include "Harl.hpp"

// PRIVATE
void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// PUBLIC
void Harl::complain ( std::string str ) {
	std::unordered_map<std::string, int> level;
	level.insert(std::pair<std::string, int>("DEBUG", 1));
	level.insert(std::pair<std::string, int>("INFO", 2));
	level.insert(std::pair<std::string, int>("WARNING", 3));
	level.insert(std::pair<std::string, int>("ERROR", 4));

	void (Harl::*ptr[5])() = {
		&Harl::debug,
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	if (level[str] > 0)
		(this->*ptr[level[str]])();
	else
		std::cerr << "String not accepted!\n";
}
