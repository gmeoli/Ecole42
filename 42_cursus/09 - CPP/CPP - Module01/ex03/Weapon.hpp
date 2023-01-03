#include <iostream>

class Weapon {

	private:
		std::string	_type;

	public:
		Weapon(std::string type);

		std::string const &getType()const;
		void setType(std::string type);
};
