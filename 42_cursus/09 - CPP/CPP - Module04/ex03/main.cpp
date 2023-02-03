#include "Cure.hpp"
#include "Ice.hpp"

#define RED "\033[31m"
#define NONE "\033[0m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

int main()
{
	std::cout << RED << "**** Constructor ****" << NONE << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	ICharacter* bob = new Character("bob");
	
	std::cout << RED << "**** Testing ****  " << NONE << std::endl;
	
	tmp = src->createMateria("ppunzo");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << RED << "**** Destructor ****" << NONE << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}