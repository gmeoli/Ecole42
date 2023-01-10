#include "Weapon.hpp"

class HumanA {
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanA(std::string name, Weapon &club);
		void attack();
};
