#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure & src);
	Cure & operator=(const Cure & src);
	~Cure();

	virtual AMateria *clone() const;
	virtual void	use(ICharacter & target);
};

#endif