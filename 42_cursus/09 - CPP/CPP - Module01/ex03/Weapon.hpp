#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string str);
		void setType(const std::string &newType);
		const std::string &getType() const;
};
