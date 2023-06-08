#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed zero;
Fixed positive(100);
Fixed negative(-100);

std::cout 	<< "VALUES" << std::endl
			<< "zero = " << zero << std::endl
			<< "positive = " << positive << std::endl
			<< "negative = " << negative << std::endl;

std::cout 	<< std::endl << "COMPARAISON TESTS" << std::endl
			<< "TEST #1 [zero > positive] : " << (zero > positive ? "true" : "false") << std::endl
			<< "TEST #2 [zero >= positive] : " << (zero >= positive ? "true" : "false") << std::endl
			<< "TEST #3 [zero >= zero] : " << (zero >= zero ? "true" : "false") << std::endl
			<< "TEST #4 [zero < positive] : " << (zero < positive ? "true" : "false") << std::endl
			<< "TEST #5 [zero <= positive] : " << (zero <= positive ? "true" : "false") << std::endl
			<< "TEST #6 [zero <= zero] : " << (zero <= zero ? "true" : "false") << std::endl
			<< "TEST #7 [zero == zero] : " << (zero == zero ? "true" : "false") << std::endl
			<< "TEST #8 [zero == positive] : " << (zero == positive ? "true" : "false") << std::endl
			<< "TEST #9 [zero != zero] : " << (zero != zero ? "true" : "false") << std::endl
			<< "TEST #10 [zero != poisitve] : " << (zero != positive ? "true" : "false") << std::endl;

std::cout 	<< std::endl << "ARITHMETIC TESTS" << std::endl
			<< "TEST #1 [zero + positive] : " << zero + positive << std::endl
			<< "TEST #2 [zero - positive] : " << zero - positive << std::endl
			<< "TEST #3 [negative * positive] : " << negative * positive << std::endl
			<< "TEST #4 [negative / positive] : " << negative / positive << std::endl;

std::cout 	<< std::endl << "INCREMENT/DECREMENT TESTS" << std::endl
			<< "TEST #1 [5++] : " << Fixed(5)++ << std::endl
			<< "TEST #2 [++5] : " << ++Fixed(5) << std::endl
			<< "TEST #3 [5--] : " << Fixed(5)-- << std::endl
			<< "TEST #4 [--5] : " << --Fixed(5) << std::endl;

Fixed const	positive_const(100);
Fixed const	negative_const(-100);
std::cout 	<< std::endl << "MIN/MAX TESTS" << std::endl
			<< "TEST #1 [min(positive, negative)] : " << Fixed::min(positive, negative) << std::endl
			<< "TEST #2 [min(positive_const, negative_const)] : " << Fixed::min(positive_const, negative_const) << std::endl
			<< "TEST #3 [max(positive, negative)] : " << Fixed::max(positive, negative) << std::endl
			<< "TEST #4 [max(positive_const, negative_const)] : " << Fixed::max(positive_const, negative_const) << std::endl;

return 0;
}

/* int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
} */