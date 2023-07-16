#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &cpy);
		WrongCat &operator=(const WrongCat &rhs);
		virtual ~WrongCat();

		virtual void	makeSound() const;
};

#endif
