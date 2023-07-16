#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const &src) {
	*this = src;
}

Point &Point::operator=(const Point &rhs) {
	if (this != &rhs)
		return (*new(this)Point(rhs._x.toFloat(), rhs._y.toFloat()));
	return (*this);
}

Point::~Point()
{
}

bool Point::operator==(Point const & rhs) const {
	if (this->_x.toFloat() == rhs._x.toFloat()
		&& this->_y.toFloat() == rhs._y.toFloat())
		return true;
	return false;
}

Fixed Point::getX() {
	return this->_x;
}
Fixed Point::getY() {
	return this->_y;
}
