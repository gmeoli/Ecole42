#include "Bureaucrat.hpp"

int main() {
	Bureaucrat	b("Carlo", 1);

	try
	{
		b.incrementGrade(1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << b;
		Bureaucrat	c(Bureaucrat("Stefano", 155));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	c = b;
		std::cout << c;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
