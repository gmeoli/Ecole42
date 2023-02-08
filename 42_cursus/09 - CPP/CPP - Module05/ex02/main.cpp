#include "Bureaucrat.hpp"

int main () {
	Bureaucrat bro( "Bro", 120);

	std::cout << bro << std::endl;

	try {
		bro.incrementGrade( 50 );
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << bro << std::endl;

	try {
		bro.incrementGrade( 100 );
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << bro << std::endl;

	AForm doc( "doc", 100, 100 );

	std::cout << doc << std::endl;

	doc.beSigned( bro );

	std::cout << doc << std::endl;

	bro.signForm( doc );

	return 0;
}
