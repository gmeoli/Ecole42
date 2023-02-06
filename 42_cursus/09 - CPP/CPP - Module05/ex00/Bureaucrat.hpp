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
		void		setGrade();
		int			inc_Grade();
		int			dec_Grade();
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif
