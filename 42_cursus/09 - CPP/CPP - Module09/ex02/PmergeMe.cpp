#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0), _sorted(false) {
	throw std::runtime_error("Error\nNo sequence provided");
}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this == &rhs)
		return *this;
	this->_deque = rhs._deque;
	this->_vector = rhs._vector;
	this->_size = rhs._size;
	this->_sorted = rhs._sorted;
	this->_deltaTimeDeque = rhs._deltaTimeDeque;
	this->_deltaTimeVector = rhs._deltaTimeVector;
	return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) : _size(0), _sorted(false) {
	_vector = _parseArgsVector(ac, av);
	_verifyDuplicates();
	_deque = _parseArgsDeque(ac, av);

	_printBeforeAndAfter(); //now Before
}

std::vector<int> PmergeMe::_parseArgsVector(int ac, char **av) {
	std::vector<int>	args;

	for (size_t i = 1; i < ac; i++) {
		std::string str = av[i];
		int value = atoi(str.c_str());
		if (value <= 0)
			std::runtime_error("Error\nInvalid argument");
		args.push_back(value);
	}
	return args;
}

std::deque<int> PmergeMe::_parseArgsDeque(int ac, char **av) {
	std::deque<int>	args;

	for (size_t i = 1; i < ac; i++) {
		std::string str = av[i];
		int value = atoi(str.c_str());
		if (value <= 0)
			std::runtime_error("Error\nInvalid argument");
		args.push_back(value);
	}
	return args;
}

void PmergeMe::_verifyDuplicates() {
	std::set<int>	numSet;

	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		int num = *it;
		if (numSet.find(num) != numSet.end())
			throw std::runtime_error("Error\nDuplicates are forbidden");
		numSet.insert(num);
	}
}

void PmergeMe::_printBeforeAndAfter() {
	if (_sorted == false)
		std::cout << "Before: ";
	else
		std::cout << "After:  ";

	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}
