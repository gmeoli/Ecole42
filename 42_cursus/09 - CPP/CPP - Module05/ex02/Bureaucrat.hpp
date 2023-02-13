#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	friend	std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat	&operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		inc_grade(int amount);
		void		dec_grade(int amount);
		void		signForm(Form &f);

		struct	GradeTooHighException : public std::exception {
			public:
				virtual const char *what(void) const _NOEXCEPT;
		};

		struct	GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const _NOEXCEPT;
		};
};
