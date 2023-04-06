#include "Classes.hpp"

int main() {
	Base	*n;

	n = generate();
	identify(n);
	identify(*n);

	return 0;
}
