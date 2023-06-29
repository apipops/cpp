#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & src):WrongAnimal(src._type)
{
}

WrongCat & WrongCat::operator=(const WrongCat & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "* WRONG MEOW *" << std::endl;
}