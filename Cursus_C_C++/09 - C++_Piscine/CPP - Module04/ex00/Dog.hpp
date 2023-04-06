#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &cpy);
		Dog &operator=(const Dog &rhs);
		virtual ~Dog();

		virtual void	makeSound() const;
};

#endif
