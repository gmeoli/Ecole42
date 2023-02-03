#include "AMateria.hpp"

AMateria::AMateria() : _type("-defaultnameMateria-")
{
	std::cout << "DEFAULT constructor AMateria created" << std::endl;
}

AMateria::AMateria(const AMateria &cpy)
{
	*this = cpy;
	std::cout << "COPY constructor AMateria created" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	std::cout << "Constructor OPERATOR AMateria created" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "Type constructor created" << std::endl;
}

std::string	const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
