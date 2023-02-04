#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public AMateria
{
	protected:
		std::string	_name;
		AMateria	*_materie[4];
	public:
		Character();
		Character(const Character &cpy);
		Character &operator=(const Character &rhs);
		~Character();

		Character(std::string const & name);
		std::string	const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif
