#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>

# define ON_FLOOR false
# define TAKEN true

class ICharacter;

class	AMateria
{
protected:
	std::string	_type;
	bool _isTaken;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria & src);
	// AMateria & operator=(const AMateria & src);
	virtual ~AMateria();

	std::string const & getType() const;
	bool getTakenStatus() const;
	void setTakenStatus(bool value);

	virtual	AMateria* clone() const = 0;
	virtual	void use(ICharacter & target);
};

#endif