#include "iter.hpp"

template <typename T>
void printInfo(T const &n)
{
	std::cout << "My value is: " << n << std::endl;
}

void printToUpper(const char &c)
{
	std::cout << (char)toupper(c);
}

void printPlusTwo(const size_t &n)
{
	std::cout << "My value is: " << n + 2 << std::endl;
}

int	main()
{
	size_t const	arr[7] = {
		5, 7, 2, 89, 45, 33, 15
	};

	std::string const	arr2[10] = {
		"dieci", "nove", "otto", "sette", "sei",
		"cinque", "quattro", "tre", "due", "uno"
	};
	
	{
		std::cout << "First attempt started" << std::endl;
		iter(arr, 7, printInfo);
		std::cout << "First attempt finished\n" << std::endl;
	}
	{
		std::cout << "Second attempt started" << std::endl;
		iter(arr, 7, printPlusTwo);
		std::cout << "Second attempt finished\n" << std::endl;
	}
	{
		std::cout << "Third attempt started" << std::endl;
		iter("ciao, sto facendo un test per vedere cose...\n", 46, printToUpper);
		std::cout << "Third attempt finished" << std::endl;
	}

	return (0);
}
