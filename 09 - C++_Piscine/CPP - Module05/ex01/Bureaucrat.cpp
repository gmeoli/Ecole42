#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.' << std::endl);
}

Bureaucrat::Bureaucrat() : _name("Mr. Burocrate"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat two-args constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{
	if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat assignement operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_grade = rhs.getGrade();
	if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::inc_grade(int amount)
{
	for (int i = 0; i < amount; i++) {
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
		this->_grade--;
	}
}

void Bureaucrat::dec_grade(int amount)
{
	for (int i = 0; i < amount; i++) {
		if (this->_grade + 1 > 150)
			throw GradeTooLowException();
		this->_grade++;
	}
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getStatus())
		std::cout << this->_name << " couldn't sign " << f.getName() << " because form is already signed!" << std::endl;
	else if (this->_grade > f.getMinGradeToSign())
		std::cout << this->_name << " couldn't sign " << f.getName() << " because bureaucrat grade is too low!" << std::endl;
	else
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	f.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Bureaucrat Exception: the grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Bureaucrat Exception: the grade is too low!");
}
