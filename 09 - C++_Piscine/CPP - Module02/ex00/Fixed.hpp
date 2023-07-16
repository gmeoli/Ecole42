#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
};

#endif
