#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	_vector;
		unsigned int		_max_N;
	public:
		Span();
		Span(Span const &cpy);
		Span &operator=(Span const &rhs);
		~Span();

		Span(unsigned int max);
		void				addNumber(int add);
		int					shortestSpan();
		int					longestSpan();
		std::vector<int>	&getVector();
};
