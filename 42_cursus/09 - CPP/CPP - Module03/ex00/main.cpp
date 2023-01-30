#include "ClapTrap.hpp"

int main() {
	ClapTrap first("Guido");
	ClapTrap second("Volpe");

	std::cout << std::endl << "-----> These ClapTraps attacking and repairing and cost 1 energy point each <-----" << std::endl << std::endl;
	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout << "Now ClapTrap second has " << second.getHealth() << " points of health and " << second.getEnergy() << " points of energy" << std::endl;
	second.attack(first.getName());
	first.takeDamage(second.getAttackDamage());
	std::cout << "Now ClapTrap first has " << first.getHealth() << " points of health and " << first.getEnergy() << " points of energy" << std::endl;
	first.beRepaired(10);
	std::cout << "Now ClapTrap first has " << first.getHealth() << " points of health and " << first.getEnergy() << " points of energy" << std::endl;
	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout << "Now ClapTrap second has " << second.getHealth() << " points of health and " << second.getEnergy() << " points of energy" << std::endl;
	second.beRepaired(5);
	std::cout << "Now ClapTrap second has " << second.getHealth() << " points of health and " << second.getEnergy() << " points of energy" << std::endl;
	
	return 0;
}
