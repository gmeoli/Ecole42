#include "ScavTrap.hpp"

int main () {

		ClapTrap bPtr = ScavTrap("again");
		ScavTrap scav("SCAVGTP");
		scav.attack("Guido");
		scav.takeDamage(6);
		scav.beRepaired(4);
		scav.takeDamage(3);
		scav.guardGate();
		scav.beRepaired(8);
		scav.takeDamage(17);

		std::cout << std::endl;

		ClapTrap clap("CLAPGTP");
		clap.attack("Handsome Jack");
		clap.takeDamage(6);
		clap.beRepaired(4);
		clap.takeDamage(3);
		clap.beRepaired(8);
		clap.takeDamage(17);

	return 0;
}