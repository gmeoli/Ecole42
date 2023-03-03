#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>();
		MutantStack<T>(MutantStack const &src);
		MutantStack &operator=(MutantStack const &rhs);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin();
		iterator	end();
};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src)
{
	*this = src;
}

template <typename T>
MutantStack<T>&MutantStack<T>::operator=(MutantStack const &rhs)
{
	(void)rhs;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}
