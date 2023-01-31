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

		std::string	getType();
		void		makeSound();
};

#endif
