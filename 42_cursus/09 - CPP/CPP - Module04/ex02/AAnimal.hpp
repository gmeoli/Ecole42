#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal &cpy);
		AAnimal	&operator=(const AAnimal &rhs);
		virtual	~AAnimal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
