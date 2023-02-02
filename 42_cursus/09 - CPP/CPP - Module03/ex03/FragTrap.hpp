#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const &copy);
		FragTrap 	&operator=(FragTrap const &rhs);
		virtual		~FragTrap();

		void		highFivesGuys(void);
};

#endif
