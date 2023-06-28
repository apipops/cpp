#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice & src):AMateria("ice")
{
	*this = src;
}

Ice & Ice::operator=(const Ice & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
