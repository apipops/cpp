#include "Point.hpp"
#include <iostream>

int main( void ) {
Point	a(0, 0);
Point	b(0, 2);
Point	c(2, 0);

Point	inside(0.5, 0.5);
Point	outside(5, 5);
Point	edge(0, 1);
Point	corner(2, 0);

std::cout 	<< "[VALUES]" << std::endl
			<< "1) triangle :" << std::endl
			<< "  - Ax = " << a.getX() << " / Ay = " << a.getY() << std::endl
			<< "  - Bx = " << b.getX() << " / By = " << b.getY() << std::endl
			<< "  - Cx = " << c.getX() << " / Cy = " << c.getY() << std::endl
			<< "2) inside : x = " << inside.getX() << " / y = " << inside.getY() << std::endl
			<< "3) outside : x = " << outside.getX() << " / y = " << outside.getY() << std::endl
			<< "4) edge : x = " << edge.getX() << " / y = " << edge.getY() << std::endl
			<< "5) corner : x = " << corner.getX() << " / y = " << corner.getY() << std::endl;

std::cout 	<< std::endl << "[TESTS]" << std::endl
			<< "TEST #1 [inside] : " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl
			<< "TEST #2 [outside] : " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl
			<< "TEST #3 [edge] : " << (bsp(a, b, c, edge) ? "true" : "false") << std::endl
			<< "TEST #4 [corner] : " << (bsp(a, b, c, corner) ? "true" : "false") << std::endl;
			
return 0;
}