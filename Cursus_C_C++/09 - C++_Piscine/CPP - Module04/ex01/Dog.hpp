#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &cpy);
		Dog 	&operator=(const Dog &rhs);
		~Dog();

		void	makeSound() const;
		Brain	*getBrain() const;
};

#endif
