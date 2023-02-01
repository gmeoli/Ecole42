#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "DEFAULT constructor Brain created" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	int	i;

	i = -1;
	while (++i < 100)
		this->_ideas[i] = cpy.getIdea(i);
	std::cout << "COPY constructor Brain created" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	int	i;

	i = -1;
	if (this == &rhs)
		return (*this);
	while (++i < 100)
		this->_ideas[i] = rhs.getIdea(i);
	std::cout << "Constructor OPERATOR Brain created" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

void Brain::setIdea(std::string s, int i)
{
	this->_ideas[i] = s;
}
