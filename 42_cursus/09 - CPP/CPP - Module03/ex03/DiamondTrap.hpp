#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap &operator=(DiamondTrap const &rhs);
		virtual		~DiamondTrap();

		using 		ScavTrap::attack;
		void		whoAmI();
};

#endif
