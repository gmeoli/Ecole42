#include "Data.hpp"

uintptr_t	serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int main() {
	Data		a(23);
	uintptr_t	b;
	Data		*c;

	b = serialize(&a);
	c = deserialize(b);

	std::cout << "'a' address: " << &a << std::endl;
	std::cout << "'a' after serialize: " << b << std::endl;
	std::cout << "'c value' after deserialize: " << c << std::endl;
	std::cout << "'data' of Data: " << c->getData() << std::endl;

	return 0;
}
