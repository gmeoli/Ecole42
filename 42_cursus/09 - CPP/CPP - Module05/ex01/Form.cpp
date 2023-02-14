#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	return (os << std::endl << "FORM'S INFORMATIONS:" << std::endl \
			<< "Name: " << rhs.getName() << std::endl \
			<< "Status: " << rhs.getStatus() << std::endl \
			<< "Grade to sign: " << rhs.getMinGradeToSign() << std::endl \
			<< "Grade to execute: " << rhs.getMinGradeToExecute() << std::endl);
}

Form::Form() : _name("Form_name"), _signed(false), _minGradeToSign(150), _minGradeToExecute(150)
{
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string const name, int minGradeToSign, int minGradeToExecute)
	: _name(name), _signed(false), _minGradeToExecute(minGradeToExecute), _minGradeToSign(minGradeToSign)
{
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form three-args constructor called" << std::endl;
}


Form::Form(const Form &src)
	: _name(src.getName()), _signed(false), _minGradeToExecute(src.getMinGradeToExecute()), _minGradeToSign(src.getMinGradeToSign())
{
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_signed = false;
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw Form::GradeTooLowException();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getStatus() const
{
	return (this->_signed);
}

int			Form::getMinGradeToSign() const
{
	return (this->_minGradeToSign);
}

int			Form::getMinGradeToExecute() const
{
	return (this->_minGradeToExecute);
}

void		Form::beSigned(Bureaucrat const &b)
{
	if (this->_signed == true)
		throw Form::AlreadySignedException();
	else if (b.getGrade() <= this->getMinGradeToSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Form Exception: the grade is too high!");
}

const char *Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Form Exception: the grade is too low!");
}

const char *Form::AlreadySignedException::what() const _NOEXCEPT
{
	return ("Bureaucrat Exception: grade too high!");
}
