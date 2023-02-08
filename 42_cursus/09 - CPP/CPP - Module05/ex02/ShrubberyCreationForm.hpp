#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm
{
	friend	std::ostream &operator<<( std::ostream &os, const ShrubberyCreationForm &rhs );
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
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const name, int gradeToSign, int gradeToExec );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		~ShrubberyCreationForm( void );

		AForm &operator=( const AForm &rhs );

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;

		void		beSigned( const Bureaucrat &obj );
};
