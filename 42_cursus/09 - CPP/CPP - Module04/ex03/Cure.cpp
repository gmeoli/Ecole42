#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "DEFAULT constructor Cure created" << std::endl;
}

Cure::Cure(const Cure &cpy)
{
	*this = cpy;
	std::cout << "COPY constructor Cure created" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	std::cout << "Constructor OPERATOR Cure created" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor Cure called" << std::endl;
}

Cure *Cure::clone() const
{
	Cure *cure = new Cure();
	return cure;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
