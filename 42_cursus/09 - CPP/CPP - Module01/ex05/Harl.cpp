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
	if (!std::all_of(str.begin(), str.end(), ::isdigit)) {
		std::cerr << "Invalid argument!\n";
		return ;
	}

	int	level = std::stoi(str);

	switch (level)
	{
	case 1:
		this->debug();
		break;
	case 2:
		this->info();
		break;
	case 3:
		this->warning();
		break;
	case 4:
		this->error();
		break;
	default:
		std::cerr << "Input not correct!" << std::endl;
		break;
	}
}
