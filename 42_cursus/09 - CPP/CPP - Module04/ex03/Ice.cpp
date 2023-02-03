#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "DEFAULT constructor Ice created" << std::endl;
}

Ice::Ice(const Ice &cpy)
{
	*this = cpy;
	std::cout << "COPY constructor Ice created" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	std::cout << "Constructor OPERATOR Ice created" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor Ice called" << std::endl;
}

Ice *Ice::clone() const
{
	Ice *ice = new Ice();
	return ice;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
