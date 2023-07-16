#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main () {
	{
		ScavTrap scav("SCAVGTP");
		scav.attack("Guido");
		scav.takeDamage(5);
		scav.beRepaired(3);
		scav.takeDamage(4);
		scav.guardGate();
		scav.beRepaired(8);
		scav.takeDamage(15);
	}
		std::cout << std::endl;
	{
		ClapTrap clap("CLAPGTP");
		clap.attack("Handsome Jack");
		clap.takeDamage(6);
		clap.beRepaired(4);
		clap.takeDamage(3);
		clap.beRepaired(8);
		clap.takeDamage(15);
	}
		std::cout << std::endl;
	{
		FragTrap frag("Forest");
		frag.takeDamage(6);
		frag.beRepaired(4);
		frag.takeDamage(3);
		frag.beRepaired(8);
		frag.takeDamage(15);
	}
	return 0;
}
