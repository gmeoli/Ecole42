#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <stdlib.h>
#include <sys/time.h>

class PmergeMe {
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		int					_size;
		bool				_sorted;
		double				_deltaTimeVector;
		double				_deltaTimeDeque;
		std::vector<int>	_parseArgsVector(int argc, char **argv);
		std::deque<int>		_parseArgsDeque(int argc, char **argv);
		void				_verifyDuplicates();
		void				_printBeforeAndAfter();
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();

		PmergeMe(int ac, char **av);
		bool	checkString(std::string const str);
};
