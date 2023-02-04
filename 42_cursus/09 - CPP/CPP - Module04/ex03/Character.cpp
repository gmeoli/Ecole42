#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_materie[i] = NULL;
	std::cout << "DEFAULT constructor Character created" << std::endl;
}

Character::Character(const Character &cpy)
{
	*this = cpy;
	this->_name = cpy.getName();
	this->_materie[4] = cpy._materie[4];
	std::cout << "COPY constructor Character created" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->_materie[i])
		{
			delete this->_materie[i];
			this->_materie[i] = NULL;
		}
		if (rhs._materie[i])
			this->_materie[i] = rhs._materie[i]->clone();
	}
	_name.assign(rhs.getName());
	this->_type = rhs._type;
	std::cout << "Constructor OPERATOR Character created" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	if (this->_materie[i])
		delete this->_materie[i];
	std::cout << "Destructor Character called" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_materie[i] = NULL;
	std::cout << "Name Character constructor called" << std::endl;
}

std::string	const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4;i++)
		if (!this->_materie[i]){
			this->_materie[i] = m;
			return ;
		}
}

void Character::unequip(int idx)
{
	std::cout << this->_materie[idx]->getType() << " unequipped at index " << idx << std::endl;
	this->_materie[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->_materie[idx])
		this->_materie[idx]->use(target);
	else
		std::cout << "Materia doesn't exist" << std::endl;
}
