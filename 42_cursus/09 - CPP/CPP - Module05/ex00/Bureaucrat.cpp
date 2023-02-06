#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default_name"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_grade = rhs.getGrade();
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::inc_Grade(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	}
}

void Bureaucrat::dec_Grade(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}
