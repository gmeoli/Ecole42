#include "Bureaucrat.hpp"

std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs )
{
	return (os << rhs.getName( ) << ", bureaucrat grade " << rhs.getGrade( ) << '.');
}

Bureaucrat::Bureaucrat( void ) : _name ("Mr. Burocrate"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name (name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat two-args constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src )
{
	*this = src;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &rhs )
{
	std::cout << "Bureaucrat assignement operator called" << std::endl;
	if ( this == &rhs )
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int	Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void Bureaucrat::inc_grade()
{
	try
	{
		if (this->getGrade() < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return;
	}
	this->_grade--;	
}

void Bureaucrat::dec_grade()
{
	try
	{
		if (this->getGrade() > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return;
	}
	this->_grade++;
}

const	char *Bureaucrat::GradeTooHighException::what( void ) const _NOEXCEPT
{
	return ("The grade is too high!");
}

const	char *Bureaucrat::GradeTooLowException::what( void ) const _NOEXCEPT
{
	return ("The grade is too low!");
}
