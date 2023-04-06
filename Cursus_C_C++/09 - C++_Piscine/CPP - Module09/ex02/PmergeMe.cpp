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

PmergeMe::PmergeMe(int ac, char **av) : _size(ac - 1), _sorted(false) {
	_vector = _parseArgsVector(ac, av); // Fill vector
	_verifyDuplicates(); // Check duplicates
	_deque = _parseArgsDeque(ac, av); // Fill deque

	_printBeforeAndAfter(); // Now: Before

	double timeBegin = _getTime(); // Init time
	_mergeInsertSort(_vector); // Sort vector
	_deltaTimeVector = _deltaTime(timeBegin); // Set time

	timeBegin = _getTime(); // Init time
	_mergeInsertSort(_deque); // Sort deque
	_deltaTimeDeque = _deltaTime(timeBegin); // Set time

	_sorted = true;
	_printBeforeAndAfter(); // Now: After

	_printTime("vector");
	_printTime("deque");
}

double PmergeMe::getDequeDeltaTime() const {
	return this->_deltaTimeDeque;
}

double PmergeMe::getVectorDeltaTime() const {
	return this->_deltaTimeVector;
}

std::vector<int> PmergeMe::_parseArgsVector(int ac, char **av) {
	std::vector<int>	args;

	for (size_t i = 1; i < ac; i++) {
		std::string str = av[i];
		int value = atoi(str.c_str());
		if (str.find_first_not_of("0123456789 ") != std::string::npos)
			throw std::runtime_error("Error\nInvalid argument");
		args.push_back(value);
	}
	return args;
}

std::deque<int> PmergeMe::_parseArgsDeque(int ac, char **av) {
	std::deque<int>	args;

	for (size_t i = 1; i < ac; i++) {
		std::string str = av[i];
		int value = atoi(str.c_str());
		if (str.find_first_not_of("0123456789 ") != std::string::npos)
			throw std::runtime_error("Error\nInvalid argument");
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

double PmergeMe::_getTime() {
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec * 0.001);
}

double PmergeMe::_deltaTime(long long time) {
	if (time > 0)
		return _getTime() - time;
	return 0;
}

template <typename T>
void	PmergeMe::_mergeInsertSort(T &container) {
	const int limit = 16;
	const int size = container.size();

	if (size <= 1)
		return ;
	if (size < limit) {
		for (typename T::iterator it = container.begin(); it != container.end(); it++) {
			typename T::iterator j = it;
			while (j != container.begin() && *(j - 1) > *j) {
				std::swap(*j, *(j - 1));
				j--;
			}
		}
		return ;
	}
	typename T::iterator middle = container.begin() + size / 2;
	T left(container.begin(), middle);
	T right(middle, container.end());

	_mergeInsertSort(left);
	_mergeInsertSort(right);

	typename T::iterator i = left.begin();
	typename T::iterator j = right.begin();
	typename T::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}
	while (i != left.end())
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != right.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

void PmergeMe::_printTime(std::string container) const {
	double	delta;

	if (container == "vector")
		delta = _deltaTimeVector;
	else if (container == "deque")
		delta = _deltaTimeDeque;
	else
		throw std::runtime_error("Error\nContainer choosen to print is not vector or deque");
	std::cout << "Time to process a range of " << _size 
		<< " elements with std::" << container << ": "
		<< std::fixed << std::setprecision(5) << delta << " ms" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PmergeMe &i) {
	o << "Vector delta time: " << i.getVectorDeltaTime() << std::endl
		<< "Deque delta time: " << i.getDequeDeltaTime();
	return o;
}
