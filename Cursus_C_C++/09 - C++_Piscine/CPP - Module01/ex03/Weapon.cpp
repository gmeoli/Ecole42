#include "Weapon.hpp"

Weapon::Weapon(std::string str) {
	this->setType(str);
}

const std::string &Weapon::getType() const {
	return this->type;
}

void Weapon::setType(const std::string &newType) {
	this->type = newType;
}
