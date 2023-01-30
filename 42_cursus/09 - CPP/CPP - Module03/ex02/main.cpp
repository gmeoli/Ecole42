#include "ScavTrap.hpp"

int main () {

		ClapTrap bPtr = ScavTrap("fight");
		ScavTrap scav("SCAVGTP");
		scav.attack("Guido");
		scav.takeDamage(5);
		scav.beRepaired(3);
		scav.takeDamage(4);
		scav.guardGate();
		scav.beRepaired(8);
		scav.takeDamage(15);

		std::cout << std::endl;

		ClapTrap clap("CLAPGTP");
		clap.attack("Handsome Jack");
		clap.takeDamage(6);
		clap.beRepaired(4);
		clap.takeDamage(3);
		clap.beRepaired(8);
		clap.takeDamage(15);

		std::cout << std::endl;


	return 0;
}
