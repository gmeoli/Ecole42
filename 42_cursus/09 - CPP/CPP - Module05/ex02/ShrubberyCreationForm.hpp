#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{			
	private:
		std::string const			_target;
		static std::string const	_trees[3];
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm();

		std::string	getTarget() const;
		void		execute(Bureaucrat const &executor) const;

		class OpenFileError : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT;
		};
};
