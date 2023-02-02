#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat 	&operator=(const Cat &rhs);
		virtual ~Cat();

		void	makeSound() const;
		Brain	*getBrain() const;
};

#endif
