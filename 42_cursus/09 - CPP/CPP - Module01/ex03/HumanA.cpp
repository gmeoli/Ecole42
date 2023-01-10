#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) {
	this->_name = name;
	this->_weapon = &club;
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}
