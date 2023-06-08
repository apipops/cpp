#include "Point.hpp"

Point::Point(void):_x(), _y()
{
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
}

Point::Point(const Point &src):_x(src.getX()), _y(src.getY())
{
}

Point&	Point::operator=(const Point &src)
{
	if (this != &src)
	{
		(Fixed)this->_x = src.getX();
		(Fixed)this->_y = src.getY();
	}
	return *this;
}

Point::~Point(void)
{
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}