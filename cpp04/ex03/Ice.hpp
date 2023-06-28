#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice & src);
	Ice & operator=(const Ice & src);
	~Ice();

	Ice *clone() const;
	virtual void	use(ICharacter & target);
};

#endif