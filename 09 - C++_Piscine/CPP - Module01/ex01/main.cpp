#include "Zombie.hpp"
#include <iostream>

int	main(void) {

	int n;
	std::cout << "Set a number of zombiessssss: ";
	std::cin >> n;
	std::cout << std::endl;

	Zombie *zombies = zombieHorde(n, "Zombie");
	for (int i = 0; i < n; i++) {
		zombies[i].announce();
	}
	delete [] zombies;

	return 0;
}
