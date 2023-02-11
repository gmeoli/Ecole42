#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
	Bureaucrat a;
	Bureaucrat b;
	Bureaucrat c;
	Bureaucrat d;

	std::cout << std::endl;
	try
	{
		Bureaucrat Luca("Luca", 150);
		a = Luca;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Francesco("Francesco", 1);
		b = Francesco;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Antonio("Antonio", -80);
		c = Antonio;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Federico("Federico", 180);
		d = Federico;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
	for (int i = 0; i < 150; i++)
		a.inc_grade();
	for (int i = 0; i < 150; i++)
		b.dec_grade();
	
	std::cout << a;
	std::cout << b;
	std::cout << std::endl;

	return 0;
}
