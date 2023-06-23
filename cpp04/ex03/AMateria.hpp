#ifndef AMETERIA_HPP
# define AMETERIA_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>
// class IChracter;

class	AMateria
{
protected:
	std::string	_type;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria & src);
	AMateria & operator=(const AMateria & src);
	virtual ~AMateria();

	std::string const & getType() const;
	virtual	AMateria* clone() const = 0;
	virtual	void use(ICharacter & target);
};

#endif