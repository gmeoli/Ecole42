#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("GuidoTrap") 
{
	this->FragTrap::setHealth(FragTrap::getHealth());
	this->ScavTrap::setEnergy(ScavTrap::getEnergy());
	this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
	ClapTrap::setName(_name + "_clap_name");
	std::cout << "DiamondTrap " << this->_name << " has been constructed with default constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : _name(name)
{
	this->FragTrap::setHealth(FragTrap::getHealth());
	this->ScavTrap::setEnergy(ScavTrap::getEnergy());
	this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
	ClapTrap::setName(_name + "_clap_name");
	std::cout << "DiamondTrap " << this->_name << " has been constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	*this = copy;
	std::cout << "Copy DiamondTrap " << this->_name << " has been constructed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->setName(rhs.ClapTrap::getName());
	this->setHealth(rhs.FragTrap::getHealth());
	this->setEnergy(rhs.ScavTrap::getEnergy());
	this->setAttackDamage(rhs.FragTrap::getAttackDamage());
	std::cout << "Copy operator overloading DiamondTrap " << this->_name << " has been constructed!" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << this->_name << ", and my ClapTrap name is: " << ClapTrap::getName() << std::endl;
}
