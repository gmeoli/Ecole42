#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "DEFAULT constructor AAnimal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &cpy)
{
	*this = cpy;
	std::cout << "COPY constructor AAnimal created" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Constructor OPERATOR AAnimal created" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor AAnimal called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "I'm just a simple AANIMAL. I can't make a sound!" << std::endl;
}
