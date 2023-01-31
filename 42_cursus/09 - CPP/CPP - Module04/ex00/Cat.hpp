#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &rhs);
		~Cat();
};

#endif
