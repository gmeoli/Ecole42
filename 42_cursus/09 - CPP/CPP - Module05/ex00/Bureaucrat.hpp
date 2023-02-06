#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat();

		Bureaucrat(std::string const &name, int grade);
		std::string	getName() const;
		int			getGrade() const;
		void		inc_Grade(int amount);
		void		dec_Grade(int amount);
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat Exception: grade too low!");
				}
		};
		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat Exception: grade too high!");
				}
		};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif
