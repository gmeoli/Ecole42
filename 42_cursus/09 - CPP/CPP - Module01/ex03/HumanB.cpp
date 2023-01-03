#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
}

void	HumanB::attack() {
	std::cout << this->_name << " attacks with their ";
	if (this->_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "really nothing" << std::endl;}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
