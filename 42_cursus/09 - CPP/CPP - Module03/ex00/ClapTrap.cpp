#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &src) {

}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {

}

ClapTrap::~ClapTrap() {

}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!"
}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
