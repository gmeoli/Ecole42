#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	friend	std::ostream &operator<<( std::ostream &os, const Form &rhs );
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int	const			_gradeToExec;

		struct	GradeTooHighException : public std::exception {
			const char *what( void ) const _NOEXCEPT;
		};

		struct	GradeTooLowException : public std::exception {
			const char *what( void ) const _NOEXCEPT;
		};
	public:
		Form( void );
		Form( std::string const name, int gradeToSign, int gradeToExec );
		Form( const Form &src );
		~Form( void );

		Form &operator=( const Form &rhs );

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;

		void		beSigned( const Bureaucrat &obj );
};
