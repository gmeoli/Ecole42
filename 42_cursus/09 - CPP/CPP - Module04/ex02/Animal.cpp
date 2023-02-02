#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "DEFAULT constructor Animal created" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	*this = cpy;
	std::cout << "COPY constructor Animal created" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Constructor OPERATOR Animal created" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "I'm just a simple ANIMAL. I can't make a sound!" << std::endl;
}
