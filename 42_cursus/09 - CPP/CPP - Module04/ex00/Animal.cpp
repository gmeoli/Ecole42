#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "DEFAULT constructor Animal created" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "COPY constructor Animal created" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Constructor OPERATOR Animal created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}

std::string	Animal::getType()
{
	return (this->type);
}
