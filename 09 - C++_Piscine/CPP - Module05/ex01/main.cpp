#include "Form.hpp"

int	main()
{
	Bureaucrat	b("Carlo", 1);

	try
	{
		b.inc_grade(1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << b;
		Bureaucrat	c(Bureaucrat("Stefano", 155));
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	c = b;
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	f("Primo form", 120, 5);
		std::cout << f;
		std::cout << b;
		b.signForm(f);
		std::cout << f;
		Form	g(f);
		Form	h("Invalid form", -1, -3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
