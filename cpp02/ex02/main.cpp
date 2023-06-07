#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed zero;
Fixed positive(100);
Fixed negative(-100);

Fixed x;

std::cout 	<< std::endl << "VALUES" << std::endl
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
			<< "TEST #1 [x = 5++] : " << Fixed(5)++ << std::endl
			<< "TEST #2 [x = ++5] : " << ++Fixed(5) << std::endl
			<< "TEST #3 [x = 5--] : " << negative * positive << std::endl
			<< "TEST #4 [x = --5] : " << negative / positive << std::endl;

return 0;
}