#include "Span.hpp"

Span::Span() : _max_N(0) {}

Span::Span(Span const &cpy)
{
	*this = cpy;
	this->_max_N = cpy._max_N;
	this->_vector = cpy._vector;
	this->_vector.reserve(this->_max_N);
}

Span &Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Span::~Span() {}

Span::Span(unsigned int max) : _max_N(max)
{
	this->_vector.reserve(max);
}

void Span::addNumber(int add)
{
	if (this->_vector.size() == this->_max_N)
		throw std::runtime_error("Span is already filled");
	this->_vector.push_back(add);
}

int Span::shortestSpan()
{
	std::vector<int>			copy;
	std::vector<int>::iterator	iter;
	int							ret;

	if (!this->_vector.size())
		throw std::runtime_error("Span is empty! Can't find span.");
	else if (this->_vector.size() == 1)
		throw std::runtime_error("Span contains only one element! Can't find span.");
	copy = this->_vector;
	std::sort(copy.begin(), copy.end());
	iter = copy.begin();
	ret = *(copy.end() - 1) - *copy.begin();
	iter++;
	for (;iter != copy.end(); iter++) {
		if (*iter - *(iter - 1) < ret)
			ret = *iter - *(iter - 1);
	}
	return ret;
}

int Span::longestSpan()
{
	std::vector<int>	copy;
	if (!this->_vector.size())
		throw std::runtime_error("Span is empty! Can't find span.");
	else if (this->_vector.size() == 1)
		throw std::runtime_error("Span contains only one element! Can't find span.");
	copy = this->_vector;
	std::sort(copy.begin(), copy.end());
	return *(copy.end() - 1) - *copy.begin();
}

std::vector<int> &Span::getVector()
{
	return (this->_vector);
}
