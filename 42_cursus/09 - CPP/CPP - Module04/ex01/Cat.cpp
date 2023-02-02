#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "DEFAULT constructor Cat created" << std::endl;
	this->type = "Cat";
	Brain *tmp = new Brain();
}

Cat::Cat(const Cat &cpy) : Animal()
{
	*this = cpy;
	this->_brain = new Brain(*cpy.getBrain());
	std::cout << "COPY constructor Cat created" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Constructor OPERATOR Cat created" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor Cat called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miiiaaooooo!!!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return _brain;
}
