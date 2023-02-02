#include "Brain.hpp"

Brain::Brain() : _index(0)
{
	std::cout << "DEFAULT constructor Brain created" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	*this = cpy;
	std::cout << "COPY constructor Brain created" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_index = rhs._index;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	std::cout << "Constructor OPERATOR Brain created" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}

void Brain::printIdeas() const
{
	for (int i = 0; i < _index; i++)
		std::cout << i << ": " << this->_ideas[i] << std::endl;
}

void Brain::setIdea(const std::string &idea)
{
	this->_ideas[_index++] = idea;
	this->_index = this->_index % 100;
}
