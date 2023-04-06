#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	friend	std::ostream &operator<<(std::ostream &os, const Form &rhs);
	private:
		std::string const	_name;
		bool				_signed;
		int const			_minGradeToSign;
		int const			_minGradeToExecute;		

	public:
		Form();
		Form(std::string const name, int minGradeToSign, int minGradeToExecute);
		Form(const Form &src);
		Form	&operator=(const Form &rhs);
		~Form();

		std::string	getName() const;
		bool		getStatus() const;
		int			getMinGradeToSign() const;
		int			getMinGradeToExecute() const;
		void		beSigned(Bureaucrat const &b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what(void) const _NOEXCEPT;
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const _NOEXCEPT;
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *what(void) const _NOEXCEPT;
		};
};
