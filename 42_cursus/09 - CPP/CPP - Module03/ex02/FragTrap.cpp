#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->setName("nameFrag");
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " has been constructed with default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string const name) {
	this->setName("nameFrag");
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " has been constructed!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) {
	*this = copy;
	std::cout << "Copy FragTrap " << this->getName() << " has been constructed!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setHealth(rhs.getHealth());
	this->setEnergy(rhs.getEnergy());
	this->setAttackDamage(rhs.getAttackDamage());
	std::cout << "Copy operator overloading FragTrap " << this->getName() << " has been constructed!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "This method belongs FragTrap's class. GIVE ME FIVE V.V" << std::endl;
}
