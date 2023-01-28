#include "ScavTrap.hpp"

int main () {
	{
		// ScavTrap one("again")
		ClapTrap	*bPtr = new ScavTrap("again");
		ScavTrap sc4vtp("sc4vtp");
		sc4vtp.attack("Handsome Jack");
		sc4vtp.takeDamage(6);
		sc4vtp.beRepaired(4);
		sc4vtp.takeDamage(3);
		sc4vtp.guardGate();
		sc4vtp.beRepaired(8);
		sc4vtp.takeDamage(17);
		delete bPtr;
	}
	// {
	// 	ClapTrap cl4ptp("cl4ptp");
	// 	cl4ptp.attack("Handsome Jack");
	// 	cl4ptp.takeDamage(6);
	// 	cl4ptp.beRepaired(4);
	// 	cl4ptp.takeDamage(3);
	// 	cl4ptp.beRepaired(8);
	// 	cl4ptp.takeDamage(17);
	// }
	return 0;
}