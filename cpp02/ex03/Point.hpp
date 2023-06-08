#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <cmath>

class	Point
{
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point & src);
	Point & operator=(const Point & src);
	~Point(void);

	Fixed	getX() const;
	Fixed	getY() const;

private:
	const Fixed	_x;
	const Fixed	_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif