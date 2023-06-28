#include "AMateria.hpp"

AMateria::AMateria():_type("unknown"),_isTaken(0)
{
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):_type(type), _isTaken(0)
{
	// std::cout << "AMateria constructor called" << std::endl;
}
	
AMateria::AMateria(const AMateria & src)
{
	*this = src;
	// std::cout << "AMateria copy constructor called" << std::endl;
}

/* AMateria & AMateria::operator=(const AMateria & src)
{
	this->_type = src._type;
	this->_isTaken = 0;
	return *this;
} */

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

bool AMateria::getTakenStatus() const
{
	return this->_isTaken;
}

void AMateria::setTakenStatus(bool status)
{
	this->_isTaken = status;
}

void AMateria::use(ICharacter & target)
{
	std::cout << "AMateria " << this->_type << "is used on " << target.getName() << "." << std::endl;
}