#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	friend	std::ostream &operator<<(std::ostream &os, const AForm &rhs);
	private:
		std::string const	_name;
		bool				_signed;
		int const			_minGradeToSign;
		int const			_minGradeToExecute;		

	public:
		AForm();
		AForm(std::string const name, int minGradeToSign, int minGradeToExecute);
		AForm(const AForm &src);
		AForm	&operator=(const AForm &rhs);
		virtual ~AForm();

		std::string			getName() const;
		bool				getStatus() const;
		int					getMinGradeToSign() const;
		int					getMinGradeToExecute() const;
		void				beSigned(Bureaucrat const &b);
		virtual std::string	getTarget() const = 0;
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT;
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT;
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT;
		};

		class NotSignedYet : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT;
		};
};
