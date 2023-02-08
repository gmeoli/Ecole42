#include "Form.hpp"

std::ostream &operator<<( std::ostream &os, const Form &rhs )
{
	os << "----Form informations----" << std::endl;
	os << "Name: " << rhs.getName() << std::endl;
	os << "Signed: " << rhs.getSigned() << std::endl;
	os << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "Grade to execute: " << rhs.getGradeToExec();
	return os;
}

Form::Form( void ) : _name ("none"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form( std::string name, int gradeToSign, int gradeToExec ) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToExec < 1)
		throw GradeTooHighException();
	std::cout << "Form three-args constructor called" << std::endl;
}

Form::Form( const Form &src ) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
		std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=( const Form &rhs )
{
	std::cout << "Form assignement operator called" << std::endl;
	if ( this == &rhs )
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

Form::~Form( void )
{
	std::cout << "Form deconstructor called" << std::endl;
}

std::string Form::getName( void ) const
{
	return this->_name;
}

bool Form::getSigned( void ) const
{
	return this->_signed;
}

int	Form::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

int	Form::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}

void Form::beSigned( const Bureaucrat &obj )
{
	if (obj.getGrade() > this->_gradeToSign)
		throw GradeTooLowException( );
	this->_signed = true;
}

const char *Form::GradeTooHighException::what( void ) const _NOEXCEPT
{
	return "The grade is too high!";
}

const char *Form::GradeTooLowException::what( void ) const _NOEXCEPT
{
	return "The grade is too low!";
}
