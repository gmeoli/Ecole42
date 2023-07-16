#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
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
		std::vector<int>	_parseArgsVector(int ac, char **av);
		std::deque<int>		_parseArgsDeque(int ac, char **av);
		void				_verifyDuplicates();
		void				_printBeforeAndAfter();
		void				_printTime(std::string container) const;

		template <typename T>
		void				_mergeInsertSort(T &container);

		double				_getTime();
		double				_deltaTime(long long time);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();

		PmergeMe(int ac, char **av);
		double	getVectorDeltaTime() const;
		double	getDequeDeltaTime() const;
};

std::ostream	&operator<<(std::ostream &o, const PmergeMe &i);
