	#include "Span.hpp"

int main() {
	Span sp = Span(20);
	std::srand(std::time(NULL)); // Inizializza il generatore di numeri casuali

	try {
		for (unsigned int i = 0; i < 20; i++)
			sp.addNumber(std::rand()); // Riempie il vettore con numeri casuali
		for (size_t num : sp.getVector()) // Ciclo "for-range" che stampa i numeri del vettore
        	std::cout << num << " ";
		std::cout << std::endl;
		// sp.addNumber(6);
		// sp.addNumber(6);
		// sp.addNumber(6);
		// sp.addNumber(6);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		// sp.addNumber(1313);
		// sp.addNumber(43);
		// sp.addNumber(67);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
