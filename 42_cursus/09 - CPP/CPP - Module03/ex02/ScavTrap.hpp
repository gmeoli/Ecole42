#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &copy);
		ScavTrap &operator=(ScavTrap const &rhs);
		~ScavTrap();

		void	attack(std::string const &target);
		void	guardGate();
};

#endif
