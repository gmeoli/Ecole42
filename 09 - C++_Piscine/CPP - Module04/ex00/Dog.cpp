#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "DEFAULT constructor Dog created" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &cpy) : Animal()
{
	*this = cpy;
	std::cout << "COPY constructor Dog created" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Constructor OPERATOR Dog created" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Baaauuuuuu!!!" << std::endl;
}
