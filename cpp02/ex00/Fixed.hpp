#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed & src);
	Fixed & operator=(const Fixed & src);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int	_value;
	static const int	_fractBits = 8;
};

#endif