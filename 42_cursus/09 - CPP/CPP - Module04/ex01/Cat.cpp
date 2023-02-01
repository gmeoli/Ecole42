#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "DEFAULT constructor Cat created" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &cpy) : Animal()
{
	*this = cpy;
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
	std::cout << "Destructor Cat called" << std::endl;
}
