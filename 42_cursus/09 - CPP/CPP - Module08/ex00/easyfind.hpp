#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator	easyfind(T &cont, int value) {
	typename T::iterator it;
	it = std::find(cont.begin(), cont.end(), value);
	if (it == cont.end())
		throw std::runtime_error("Value not found!");
	return it;
}
