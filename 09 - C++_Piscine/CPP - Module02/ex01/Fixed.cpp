#include "Fixed.hpp"

Fixed::Fixed( void ) : _m_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyFixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called"<< std::endl;
	this->_m_value = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called"<< std::endl;
	return (this->_m_value);
}

void Fixed::setRawBits( int const raw ) {
	this->_m_value = raw;
}

Fixed::Fixed( const int _num_int ) :
	_m_value(_num_int << this->_nbits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float _num_float ) :
	_m_value(roundf(_num_float * (1 << this->_nbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_m_value / ( 1 << this->_nbits));
}
	
int Fixed::toInt( void ) const {
	return (this->_m_value >> this->_nbits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return os;
}
