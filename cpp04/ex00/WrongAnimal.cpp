#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("unknown")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):_type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & src):_type(src._type)
{
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "* WRONG ANIMAL SOUND *" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}