#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_dmg;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &rhs);
		ClapTrap 	&operator=(ClapTrap const &rhs);
		virtual 	~ClapTrap();

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName() const;
		int			getHealth() const;
		int			getEnergy() const;
		int			getAttackDamage() const;
		void		setName(std::string name);
		void		setHealth(unsigned int amount);
		void		setEnergy(unsigned int amount);
		void		setAttackDamage(unsigned int amount);
};

#endif
