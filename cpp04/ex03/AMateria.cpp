#include "AMateria.hpp"

AMateria::AMateria():_type("unknown"),_isTaken(0)
{
}

AMateria::AMateria(std::string const & type):_type(type), _isTaken(0)
{
}
	
AMateria::AMateria(const AMateria & src)
{
	*this = src;
}

AMateria & AMateria::operator=(const AMateria & src)
{
	this->_type = src._type;
	return *this;
}

AMateria::~AMateria()
{
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