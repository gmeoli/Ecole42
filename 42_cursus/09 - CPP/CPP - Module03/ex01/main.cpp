#include "ScavTrap.hpp"

int main () {

	ScavTrap first;
	ScavTrap b(first);
	ClapTrap second;

	second = b;

	// second.attack("Guido");

	return 0;
}