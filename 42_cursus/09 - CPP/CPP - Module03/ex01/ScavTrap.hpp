#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		/* data */
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &copy);
		ScavTrap &operator=(ScavTrap const &copy_over);
		~ScavTrap();
};

#endif
