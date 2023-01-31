#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
	public:
		Dog();
		Dog(const Dog &cpy);
		Dog &operator=(const Dog &rhs);
		~Dog();
};

#endif
