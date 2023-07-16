#include "Zombie.hpp"
#include <iostream>

Zombie::~Zombie(void) {

	std::cout << this->name << " is dead" << std::endl;
	return ;
}

void	Zombie::setName(std::string _name) {

	this->name = _name;
	return ;
}

void	Zombie::announce(void) {
	
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
