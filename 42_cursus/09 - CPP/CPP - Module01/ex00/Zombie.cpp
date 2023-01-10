#include "Zombie.hpp"

/*---- public ----*/

Zombie::Zombie(std::string name)
{
	this->name = name;
	return;
}

Zombie::~Zombie()
{
	std::cout << std::endl << name << "is dead" << std::endl;
	return;
}

void Zombie::announce()
{
	std::cout << Zombie::name << "BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
