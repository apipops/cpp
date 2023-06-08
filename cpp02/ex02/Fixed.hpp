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

	bool	operator<(const Fixed & elem);
	bool	operator>(const Fixed & elem);
	bool	operator<=(const Fixed & elem);
	bool	operator>=(const Fixed & elem);
	bool	operator==(const Fixed & elem);
	bool	operator!=(const Fixed & elem);

	Fixed	operator+(const Fixed & elem);
	Fixed	operator-(const Fixed & elem);
	Fixed	operator*(const Fixed & elem);
	Fixed	operator/(const Fixed & elem);

	/* 
	Norme pour différencier opérateurs préfixée et suffixés :
	(http://casteyde.christian.free.fr/cpp/cours/online/x3244.html#:~:text=Le%20C%2B%2B%20permet%20donc%20de,d%C3%A9finir%20des%20fonctions%20membres%20normales)
		- préfixés : prend (void) et renvoie une référence, égale à la valeur incrémentée
		- suffixés : prend (int) et renvoie la valeur de l'objet, égale à la valeur avant incrémentation
	*/
	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int); 
	Fixed	operator--(int);

	static Fixed& min(Fixed & a, Fixed & b);
	static const Fixed&	min(const Fixed & a, const Fixed & b);
	static Fixed& max(Fixed & a, Fixed & b);
	static const Fixed&	max(const Fixed & a, const Fixed & b);

private:
	int	_value;
	static const int	_fractBits = 8;
};

std::ostream & operator<<(std::ostream & out, Fixed const & element);

#endif