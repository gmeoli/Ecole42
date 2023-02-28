#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <time.h>
#include <cmath>

template <typename T>
struct s_elRandom {
	
	typedef T(*t_at_random)( int rand_lim );

	public:
		s_elRandom( int limit, t_at_random at_random ) : _limit(limit), _at_random(at_random) {}
		
		void	operator() ( T& el ) {
			el = _at_random( _limit + 1 );
		}
		
	private:
		const int	_limit;
		t_at_random	_at_random;
};

template <typename T>
void	print_el( T el ) {
	std::cout << el << std::endl;
}

template <typename T>
int	easyfind(T &cont, int value) {
	typename T::iterator	it;
	typename T::iterator	start = cont.begin();
	typename T::iterator	end = cont.end();

	it = std::find(start, end, value);
	if (it != cont.end()) {
		std::cout << value << " found at position: " << it - start << std::endl;
		return *it;
	}
	else
		throw std::runtime_error("Value not found!");
}
