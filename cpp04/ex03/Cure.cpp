#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure & src):AMateria("cure")
{
	*this = src;
}

Cure & Cure::operator=(const Cure & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
