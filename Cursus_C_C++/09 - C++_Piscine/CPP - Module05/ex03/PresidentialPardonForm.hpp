#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{			
	private:
		std::string const	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm();

		std::string	getTarget() const;
		void		execute(Bureaucrat const &executor) const;
};
