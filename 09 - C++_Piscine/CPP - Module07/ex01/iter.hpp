#pragma once

#include <iostream>

template <typename T>
void iter(const T *array, size_t len_array, void (*function)(const T &)) {
	for (size_t i = 0; i < len_array; i++)
		function(array[i]);
}
