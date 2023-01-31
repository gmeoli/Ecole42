#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "DEFAULT constructor Dog created" << std::endl;
}

Dog::Dog(const Dog &cpy)
{
	std::cout << "COPY constructor Dog created" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Constructor OPERATOR Dog created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
}
