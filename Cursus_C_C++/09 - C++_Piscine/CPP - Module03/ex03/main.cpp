#include "DiamondTrap.hpp"

int main () {
	{
		DiamondTrap diamond("DiamondGTP");
		diamond.attack("Handsome Jack");
		diamond.takeDamage(6);
		diamond.beRepaired(4);
		diamond.takeDamage(3);
		diamond.guardGate();
		diamond.beRepaired(8);
		diamond.takeDamage(17);
		diamond.whoAmI();
	}
	return 0;
}
