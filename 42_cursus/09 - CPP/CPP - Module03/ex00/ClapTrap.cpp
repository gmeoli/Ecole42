#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10) ,_energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap " << name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this == &rhs)
		return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap has been destructed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hit_points <= 0 || this->_energy_points <= 0) {
		std::cout << "You don't have Energy points or Hit points to subtract!" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!";
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_energy_points -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points <= 0 || this->_energy_points <= 0) {
		std::cout << "You don't have Energy points or Hit points to subtract!" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " repaired it self of " << amount << " points. Using " << this->_energy_points << " points of energy!";
}
