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
	return (this->_nbits);
}
void Fixed::setRawBits( int const raw ) {
	this->_m_value = raw;
}
