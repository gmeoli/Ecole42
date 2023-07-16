#include "HumanA.hpp"

class HumanB {
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &_club);
};
