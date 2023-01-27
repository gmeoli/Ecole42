#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap has been constructed with default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) {
	std::cout << "Copy ScavTrap has been constructed!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) {
	std::cout << "Copy ScavTrap " << this->getName() << " has been constructed!" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	if (this == &rhs)
		return (*this);
	std::cout << "Copy operator overloading ClapTrap " << this->getName() << " has been constructed!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(std::string const &target) {

}

void ScavTrap::ScavTrap::guardGate() {

}
