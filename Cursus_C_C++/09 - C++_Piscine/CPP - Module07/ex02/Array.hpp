#pragma once

#include <iostream>

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

template <typename T>
Array<T>::Array() : _n(0), _array(NULL)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _array(new T[n])
{}

template <typename T>
Array<T>::Array(Array const &cpy) : _n(cpy.size()), _array(new T[this->_n])
{
	for (size_t i = 0; i < this->_n; i++)
		this->_array[i] = cpy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_n = rhs.size();
	for (size_t i = 0; i < this->_n;i++)
		this->_array[i] = rhs._array[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](int index) const
{
	if (index < 0 || index >= (int)this->_n)
		throw IndexOutOfBoundException();
	return (this->_array[index]);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_n)
		delete[] this->_array;
}

template <typename T>
size_t Array<T>::size() const
{
	return this->_n;
}

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw()
{
	return ("Index out of bound");
}
