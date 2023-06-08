#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const int number)
{
	this->_value = (number << _fractBits);
}

Fixed::Fixed(const float number)
{
	this->_value = static_cast<int>(std::roundf(number * (1 << _fractBits)));
}

Fixed::Fixed(const Fixed & src)
{
	*this = src;
}

Fixed & Fixed::operator=(const Fixed & src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << _fractBits));
}

int	Fixed::toInt(void) const
{
	return this->_value >> _fractBits;
}

/* COMPARAISON OPERATORS */

bool	Fixed::operator<(const Fixed & elem)
{
	return (this->getRawBits() < elem.getRawBits());
}

bool	Fixed::operator>(const Fixed & elem)
{
	return (this->getRawBits() > elem.getRawBits());
}

bool	Fixed::operator<=(const Fixed & elem)
{
	return (this->getRawBits() <= elem.getRawBits());
}
	
bool	Fixed::operator>=(const Fixed & elem)
{
	return (this->getRawBits() >= elem.getRawBits());
}

bool	Fixed::operator==(const Fixed & elem)
{
	return (this->getRawBits() == elem.getRawBits());
}

bool	Fixed::operator!=(const Fixed & elem)
{
	return (this->getRawBits() != elem.getRawBits());
}

/* ARITHMETIC OPERATORS */

Fixed	Fixed::operator+(const Fixed & elem)
{
	return (Fixed(this->toFloat() + elem.toFloat()));
}

Fixed	Fixed::operator-(const Fixed & elem)
{
	return (Fixed(this->toFloat() - elem.toFloat()));
}
Fixed	Fixed::operator*(const Fixed & elem)
{
	return (Fixed(this->toFloat() * elem.toFloat()));
}
Fixed	Fixed::operator/(const Fixed & elem)
{
	return (Fixed(this->toFloat() / elem.toFloat()));
}

/* INCREMENT & DECREMENT OPERATORS */
	
Fixed&	Fixed::operator++(void)
{
	++this->_value;
	return *this;
}

Fixed&	Fixed::operator--(void)
{
	--this->_value;
	return *this;
}

Fixed	Fixed::operator++(int)
{
    Fixed old(*this);
    ++this->_value;
    return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed old(*this);
	--this->_value;
	return old;
}

/* MIN & MAX FUNCTIONS */

Fixed&	Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed&	Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

/* REDIRECTION OPERATORS */

std::ostream & operator<<(std::ostream & out, Fixed const & element)
{
	out << element.toFloat();
	return out;
}