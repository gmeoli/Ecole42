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
		Fixed( const int _num_int );
		Fixed( const float _num_float );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed operator+( const Fixed &copy );
		Fixed operator-( const Fixed &copy );
		Fixed operator/( const Fixed &copy );
		Fixed operator*( const Fixed &copy );
		bool operator>( const Fixed &copy );
		bool operator<( const Fixed &copy );
		bool operator>=( const Fixed &copy );
		bool operator<=( const Fixed &copy );
		bool operator==( const Fixed &copy );
		bool operator!=( const Fixed &copy );
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
