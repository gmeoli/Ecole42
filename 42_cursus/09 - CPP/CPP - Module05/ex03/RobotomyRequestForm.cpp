#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("no target")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm target-arg constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: AForm(src.getName(), src.getMinGradeToSign(), src.getMinGradeToExecute())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int random = rand() % 2;

	if (!this->getStatus())
		throw AForm::NotSignedYet();
	if (executor.getGrade() > this->getMinGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Beeepbeepbzbzbzztzb... robotizing in progress.. ZBZ" << std::endl;
	if (random)
		std::cout << this->_target << " has been robotized successfully!" << std::endl;
	else
		std::cout << "Unfortunately, ROBOTOMY failed. Try again!" << std::endl;
}
