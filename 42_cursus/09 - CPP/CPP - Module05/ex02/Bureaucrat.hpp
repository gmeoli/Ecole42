#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	friend	std::ostream &operator<<( std::ostream &os, const Bureaucrat &obj );
	private:
		std::string const	_name;
		int					_grade;

		struct	GradeTooHighException : public std::exception {
			const char *what( void ) const _NOEXCEPT;
		};

		struct	GradeTooLowException : public std::exception {
			const char *what( void ) const _NOEXCEPT;
		};
	public:
		Bureaucrat( void );
		Bureaucrat( std::string const name, int grade );
		Bureaucrat( const Bureaucrat &src );
		~Bureaucrat( void );

		Bureaucrat	&operator=( const Bureaucrat &rhs );

		std::string getName( void ) const;
		int			getGrade( void ) const;
		void		decrementGrade( int decrement );
		void		incrementGrade( int increment );

		void		signForm( const Form &obj ) const ;
};
