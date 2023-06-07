#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int number)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = (number << _fractBits);
}

Fixed::Fixed(const float number)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(std::roundf(number * (1 << _fractBits)));
}

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(const Fixed & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
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
	
Fixed	Fixed::operator++(void)
{
	++this->_value;
	return *this;
}

Fixed	Fixed::operator++(int)
{
    Fixed tmp( *this );
    ++this->_value;
    return tmp;
}
Fixed&	Fixed::operator--(void)
{
	--this->_value;
	return *this;
}
Fixed&	Fixed::operator--(int)
{
	this->_value--;
	return *this;
}

std::ostream & operator<<(std::ostream & out, Fixed const & element)
{
	out << element.toFloat();
	return out;
}