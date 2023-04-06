#include "ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::_trees[3] =
{
	"      o\n"
    "     /|\\\n"
    "    / | \\\n"
    "   /  |  \\\n"
    "  /   |   \\\n"
    " /____|____\\\n"
    "  /     \\ \n"
    " /       \\\n"
    "/_________\\\n"
};

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), _target("no target")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 147, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm target-arg constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: AForm(src.getName(), src.getMinGradeToSign(), src.getMinGradeToExecute())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getMinGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getStatus())
		throw AForm::NotSignedYet();

	std::string const filename = this->_target + "_shrubbery";
	std::ofstream output;
	output.open(filename.c_str(), std::ios_base::out);
	if (!output.is_open() || output.bad())
		throw ShrubberyCreationForm::OpenFileError();
	for (int i = 0; i < 3; i++) {
		output << ShrubberyCreationForm::_trees[i];
	}
	output.close();
	std::cout << executor.getName() << " has executed " << this->getName() << std::endl;
}

const char *ShrubberyCreationForm::OpenFileError::what() const _NOEXCEPT
{
	return ("ShrubberyCreationForm Exception: error while opening file!");
}
