#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{			
	private:
		std::string const	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm();

		std::string	getTarget() const;
		void		execute(Bureaucrat const &executor) const;
};
