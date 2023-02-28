#pragma once

#include <iostream>

class Span
{
	private:
		unsigned int	_N;
	public:
		Span();
		Span(Span const &cpy);
		Span &operator=(Span const &rhs);
		~Span();

		Span(unsigned int max);
		void	addNumber(int add);
		int		shortestSpan();
		int		longestSpan();
};
