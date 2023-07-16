#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->setName("no_name");
	this->setHealth(100);
	this->setEnergy(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " has been constructed with default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) {
	this->setName(name);
	this->setHealth(100);
	this->setEnergy(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) {
	*this = copy;
	std::cout << "Copy ScavTrap " << this->getName() << " has been constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setHealth(rhs.getHealth());
	this->setEnergy(rhs.getEnergy());
	this->setAttackDamage(rhs.getAttackDamage());
	std::cout << "Copy operator overloading ScavTrap " << this->getName() << " has been constructed!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1); 
}

void ScavTrap::ScavTrap::guardGate() {
	std::cout << getName() << ": Gate keeper mode!" << std::endl;
}
