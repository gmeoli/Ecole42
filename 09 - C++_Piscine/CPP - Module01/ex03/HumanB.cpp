#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

void HumanB::attack() {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << "NO WEAPON!\n";
}

void  HumanB::setWeapon(Weapon &_club) {
	this->_weapon = &_club;
}
