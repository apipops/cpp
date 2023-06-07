#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
public:
	Fixed(void);
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed & src);
	Fixed & operator=(const Fixed & src);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int	_value;
	static const int	_fractBits = 8;
};

std::ostream & operator<<(std::ostream & out, Fixed const & element);

#endif