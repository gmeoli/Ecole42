#include "Array.hpp"

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
Array<T>&Array<T>::operator=(Array const &rhs)
{
}

template <typename T>
T &Array::operator[](int index) const
{
}

template <typename T>
Array<T>::~Array()
{
	if (this->_n)
		delete this->_array;
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
