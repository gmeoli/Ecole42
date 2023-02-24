#include "Array.hpp"

int main() {
	int	i;
	Array<int>		tab(5);
	Array<char>		tab_char(3);
	Array<char>		tab_char2(3);
	Array<float>	tab_float;

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	tab[4] = 4;
	
	std::cout << "--- Test 1 ---" << std::endl;
	std::cout << "size: " << tab.size() << std::endl;
	for (i = 0; i < (int)tab.size(); i++)
	{
		if (i == 0)
			std::cout << "value: [";
		if (i >= 0 && i < (int)(tab.size() - 1))
			std::cout << tab[i] << ", ";
		else
			std::cout << tab[i] << "]" << std::endl;
	}
	try
	{
		std::cout << tab[5] << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << "Get element from unset cell" << std::endl;
		std::cerr << e.what() << '\n';
	}
	
	tab_char[0] = 'a';
	tab_char[1] = 'b';
	tab_char[2] = 'c';
	std::cout << std::endl << std::endl;
	std::cout << "--- Test 2 tab_char---" << std::endl;
	std::cout << "size: " << (int)tab_char.size() << std::endl;
	for (i = 0; i < (int)tab_char.size(); i++)
	{
		if (i == 0)
			std::cout << "value: [";
		if (i >= 0 && i < (int)(tab_char.size() - 1))
			std::cout << tab_char[i] << ", ";
		else
			std::cout << tab_char[i] << "]" << std::endl;
	}
	try
	{
		std::cout << tab_char[5] << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << "Get element from unset cell" << std::endl;
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << std::endl;
	std::cout << "--- Test 3 ---" << std::endl;
	try {
		std::cout << tab_float[0] << std::endl;}
	catch(std::exception const &e) {
		std::cout << "Get element of empty array" << std::endl;
		std::cerr << e.what() << '\n'; }

	std::cout << std::endl << std::endl;
	std::cout << "--- Test 4 ---" << std::endl;
	std::cout << "assignation (=) tab_char2 = tab_char" << std::endl;
	tab_char2 = tab_char;
	for (i = 0; i < (int)tab_char2.size(); i++)
	{
		if (i == 0)
			std::cout << "value: [";
		if (i >= 0 && i < (int)(tab_char2.size() - 1))
			std::cout << tab_char2[i] << ", ";
		else
			std::cout << tab_char2[i] << "]" << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "--- Test 5 ---" << std::endl;
	std::cout << "constructor copy tab_char3(tab_char2)" << std::endl;
	Array<char>		tab_char3(tab_char2);
	for (i = 0; i < (int)tab_char3.size(); i++)
	{
		if (i == 0)
			std::cout << "value: [";
		if (i >= 0 && i < (int)(tab_char3.size() - 1))
			std::cout << tab_char3[i] << ", ";
		else
			std::cout << tab_char3[i] << "]" << std::endl;
	}

	return 0;
}