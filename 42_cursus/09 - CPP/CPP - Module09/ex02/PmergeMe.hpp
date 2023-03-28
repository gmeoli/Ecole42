#pragma once

#include <iostream>
#include <string>
#include <queue>

class PmergeMe {
	private:
		std::queue<int>	_sequence;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();
};
