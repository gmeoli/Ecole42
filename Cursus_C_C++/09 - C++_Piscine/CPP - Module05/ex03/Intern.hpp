#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		static std::string const	_forms[3];
		int							_idx;
		int							_nForms;
	public:
		Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &rhs);
		~Intern();

		void	searchForm(std::string f);
		AForm	*makeForm(std::string f, std::string target);
		class NoExistingForm : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT;
		};
};
