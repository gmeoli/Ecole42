#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_dmg(0) {
	std::cout << "ClapTrap " << name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs) {
	std::cout << "Copy ClapTrap " << this->getName() << " has been constructed!" << std::endl;
	*this = rhs;	
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int	ClapTrap::getHealth(void) const {
	return (this->_hit_points);
}

int	ClapTrap::getEnergy(void) const {
	return (this->_energy_points);
}

int	ClapTrap::getAttackDamage(void) const {
	return (this->_attack_dmg);
}

void	ClapTrap::setHealth(unsigned int amount) {
	this->_hit_points = amount;
}

void	ClapTrap::setEnergy(unsigned int amount) {
	this->_energy_points = amount;
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attack_dmg = amount;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setHealth(rhs.getHealth());
	this->setEnergy(rhs.getEnergy());
	this->setAttackDamage(rhs.getAttackDamage());
	std::cout << "Copy operator overloading ClapTrap " << this->getName() << " has been constructed!" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	this->setAttackDamage(this->getAttackDamage() + 1);
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	this->setHealth(this->getHealth() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->getName() << " gets " << amount << " points of health, loses one point of energy." << std::endl;
	this->setHealth(this->getHealth() + amount);
	this->setEnergy(this->getEnergy() - 1);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->getName() << " has been destroyed!" << std::endl;
}
