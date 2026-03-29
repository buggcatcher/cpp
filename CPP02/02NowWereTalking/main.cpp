#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

    Fixed c(12.34f);

	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << c << std::endl;
	std::cout << c * 0.5f << std::endl;
	std::cout << c / 0.5f << std::endl;

	a = 7.77f;
	std::cout << a << std::endl;
	std::cout << a + 0.22f << std::endl;
	std::cout << a - 0.76f << std::endl;
	
    return 0;
}