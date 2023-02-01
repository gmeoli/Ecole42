#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <array>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &cpy);
		Brain &operator=(const Brain &rhs);
		virtual ~Brain();

		std::string	getIdea(int i) const;
		void		setIdea(std::string s, int i);
};

#endif
