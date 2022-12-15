#include "Zombie.hpp"

int main(void) {

	std::cout << "Test One:" << std::endl;
	Zombie zombie("Guido ");
	zombie.announce();

	std::cout << "\nTest Two:" << std::endl;
	Zombie *test2 = new Zombie("gmeoli ");
	test2->announce();

	std::cout << "\nTest Three:" << std::endl;
	randomChump("DisGuizzzz ");
	delete test2;

	return 0;
}
