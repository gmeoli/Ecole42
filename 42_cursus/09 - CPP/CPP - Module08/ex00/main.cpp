#include "easyfind.hpp"

int	main()
{
	{
		std::cout << "Code with LIST" << std::endl;
		std::list<int>	arr;

		arr.push_back(2);
		arr.push_back(13);
		arr.push_back(17);
		arr.push_back(23);
		arr.push_back(5);
		arr.push_back(26);
		arr.push_back(94);
		arr.push_back(-23);

		try
		{
			std::cout << *(::easyfind(arr, 5)) << std::endl;
			std::cout << *(::easyfind(arr, 26)) << std::endl;
			std::cout << *(::easyfind(arr, -1)) << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Code with VECTOR" << std::endl;
		std::vector<int>	arr2;

		arr2.push_back(2);
		arr2.push_back(13);
		arr2.push_back(17);
		arr2.push_back(23);
		arr2.push_back(5);
		arr2.push_back(26);
		arr2.push_back(94);
		arr2.push_back(-23);

		try
		{
			std::cout << *(::easyfind(arr2, 5)) << std::endl;
			std::cout << *(::easyfind(arr2, 94)) << std::endl;
			std::cout << *(::easyfind(arr2, -1)) << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
