#include "AForm.hpp"

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	return (os << "AFORM'S INFORMATIONS:" \
			<< "Name: " << rhs.getName() << std::endl \
			<< "Status: " << rhs.getStatus() << std::endl \
			<< "Grade to sign: " << rhs.getMinGradeToSign() << std::endl \
			<< "Grade to execute: " << rhs.getMinGradeToExecute() << std::endl);
}

AForm::AForm() : _name("AForm_name"), _signed(false), _minGradeToSign(150), _minGradeToExecute(150)
{
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string const name, int minGradeToSign, int minGradeToExecute)
	: _name(name), _signed(false), _minGradeToExecute(minGradeToExecute), _minGradeToSign(minGradeToSign)
{
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm three-args constructor called" << std::endl;
}


AForm::AForm(const AForm &src)
	: _name(src.getName()), _signed(false), _minGradeToExecute(src.getMinGradeToExecute()), _minGradeToSign(src.getMinGradeToSign())
{
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_signed = false;
	if (this->_minGradeToExecute < 1 || this->_minGradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_minGradeToExecute > 150 || this->_minGradeToSign > 150)
		throw AForm::GradeTooLowException();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getStatus() const
{
	return (this->_signed);
}

int			AForm::getMinGradeToSign() const
{
	return (this->_minGradeToSign);
}

int			AForm::getMinGradeToExecute() const
{
	return (this->_minGradeToExecute);
}

void		AForm::beSigned(Bureaucrat const &b)
{
	if (this->_signed == true)
		throw AForm::AlreadySignedException();
	else if (b.getGrade() <= this->getMinGradeToSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return ("AForm Exception: the grade is too high!");
}

const char *AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return ("AForm Exception: the grade is too low!");
}

const char *AForm::AlreadySignedException::what() const _NOEXCEPT
{
	return ("AForm Exception: form is already signed!");
}

const char *AForm::NotSignedYet::what() const _NOEXCEPT
{
	return ("AForm Exception: form is not yet signed. You can't execute!");
}
