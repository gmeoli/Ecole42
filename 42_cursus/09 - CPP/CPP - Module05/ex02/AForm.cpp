#include "AForm.hpp"

std::ostream &operator<<( std::ostream &os, const AForm &rhs )
{
	os << "----AForm inAformations----" << std::endl;
	os << "Name: " << rhs.getName() << std::endl;
	os << "Signed: " << rhs.getSigned() << std::endl;
	os << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "Grade to execute: " << rhs.getGradeToExec();
	return os;
}

AForm::AForm( void ) : _name ("none"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExec ) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToExec < 1)
		throw GradeTooHighException();
	std::cout << "AForm three-args constructor called" << std::endl;
}

AForm::AForm( const AForm &src ) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
		std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=( const AForm &rhs )
{
	std::cout << "AForm assignement operator called" << std::endl;
	if ( this == &rhs )
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

AForm::~AForm( void )
{
	std::cout << "AForm deconstructor called" << std::endl;
}

std::string AForm::getName( void ) const
{
	return this->_name;
}

bool AForm::getSigned( void ) const
{
	return this->_signed;
}

int	AForm::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

int	AForm::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}

void AForm::beSigned( const Bureaucrat &obj )
{
	if (obj.getGrade() > this->_gradeToSign)
		throw GradeTooLowException( );
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what( void ) const _NOEXCEPT
{
	return "The grade is too high!";
}

const char *AForm::GradeTooLowException::what( void ) const _NOEXCEPT
{
	return "The grade is too low!";
}
