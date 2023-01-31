#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "DEFAULT constructor WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal()
{
	*this = cpy;
	std::cout << "COPY constructor WrongCat created" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Constructor OPERATOR WrongCat created" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Who are you?!" << std::endl;
}
