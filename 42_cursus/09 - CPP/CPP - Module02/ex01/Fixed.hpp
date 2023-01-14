#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed {
	private:
		int _m_value;
		static const int _nbits = 8;
	public:
		Fixed( void );
		Fixed(const Fixed &copyFixed);
		Fixed &operator=(const Fixed &copy);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed( const int _num_int );
		Fixed( const float _num_float );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
