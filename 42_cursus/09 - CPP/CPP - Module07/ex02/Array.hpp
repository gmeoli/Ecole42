#pragma once

#include <iostream>
#include "Array.tpp"

template <typename T>
class Array
{
	private:
		unsigned int	_n;
		T				*_array;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &cpy);
		Array &operator=(Array const &rhs);
		T &operator[](int index) const;
		~Array();

		size_t	size() const;

		class IndexOutOfBoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
