#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &cpy);
		Animal &operator=(const Animal &rhs);
		~Animal();

		void	getType();
};

#endif
