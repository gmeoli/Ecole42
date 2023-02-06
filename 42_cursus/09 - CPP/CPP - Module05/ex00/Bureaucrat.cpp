#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Burocrate")
{

}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name("Mr. Burocrate")
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->getName() = rhs.getName();
	this->getGrade() = rhs.getGrade();
	this->inc_Grade() = rhs.inc_Grade();
	this->dec_Grade() = rhs.dec_Grade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade()
{

}

int Bureaucrat::inc_Grade()
{

}

int Bureaucrat::dec_Grade()
{

}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
		return os;
}
