#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
		int			_index;
	public:
		Brain();
		Brain(const Brain &cpy);
		Brain	&operator=(const Brain &rhs);
		virtual	~Brain();

		void	printIdeas() const;
		void	setIdea(const std::string &idea);
};

#endif
