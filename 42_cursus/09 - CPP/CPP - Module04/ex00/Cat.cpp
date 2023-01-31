#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "DEFAULT constructor Cat created" << std::endl;
}

Cat::Cat(const Cat &cpy)
{
	std::cout << "COPY constructor Cat created" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Constructor OPERATOR Cat created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called" << std::endl;
}
