#include "Bureaucrat.hpp"

std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs )
{
	os << rhs.getName( ) << ", bureaucrat grade " << rhs.getGrade( ) << '.';
	return os;
}

Bureaucrat::Bureaucrat( void ) : _name ("Mr. Burocrate")
{
	_grade = 150;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name (name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
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

void	Bureaucrat::decrementGrade( int decrement )
{
	if (_grade + decrement > 150)
		throw GradeTooLowException();
	_grade += decrement;
}

void	Bureaucrat::incrementGrade( int increment )
{
	if (_grade - increment < 1)
		throw GradeTooHighException();
	_grade -= increment;
}

void	Bureaucrat::signForm( const AForm &obj ) const
{
	if (obj.getSigned( ) == true)
		std::cout << this->_name << " signed " <<  obj.getName( ) << std::endl;
	else
	{
		std::cout << this->_name << " couldn't sign " <<  obj.getName( );
		std::cout << " because he's grade is to low." << std::endl;
	}
}

const	char *Bureaucrat::GradeTooHighException::what( void ) const _NOEXCEPT
{
	return "The grade is too high!";
}

const	char *Bureaucrat::GradeTooLowException::what( void ) const _NOEXCEPT
{
	return "The grade is too low!";
}
