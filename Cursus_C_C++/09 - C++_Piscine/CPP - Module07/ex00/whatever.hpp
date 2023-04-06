#pragma once

#include <iostream>

template <typename T>
void swap(T &x, T &y) {
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(T x, T y) {
	return (x < y) ? x : y;
}

template <typename T>
T max(T x, T y) {
	return (x > y) ? x : y;
}
