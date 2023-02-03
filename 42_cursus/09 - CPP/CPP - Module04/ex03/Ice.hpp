#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &cpy);
		Ice &operator=(const Ice &rhs);
		~Ice();

		Ice *clone() const;
		void use(ICharacter &target);
};

#endif
