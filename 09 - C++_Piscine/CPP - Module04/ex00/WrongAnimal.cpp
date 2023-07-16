#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "DEFAULT constructor WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) : type("WrongAnimal")
{
	*this = cpy;
	std::cout << "COPY constructor WrongAnimal created" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Constructor OPERATOR WrongAnimal created" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "I'm just a simple WRONGANIMAL. I can't make a sound!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
