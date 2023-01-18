#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>

class Point {
	private:
	public:
		Point( void );
		Point( const Point &copyPoint );
		Point &operator=(const Point &copy);		
		~Point();
};

#endif
