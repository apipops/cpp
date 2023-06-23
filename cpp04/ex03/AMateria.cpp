#include "AMateria.hpp"

AMateria::AMateria():_type("unknown")
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):_type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}
	
AMateria::AMateria(const AMateria & src)
{
	*this = src;
}

AMateria & AMateria::operator=(const AMateria & src)
{
	if (*this != src)
		this->_type = src._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter & target)
{
	std::cout << "AMateria " << this->_type << "is used on " << target.getName() << std::endl;
}