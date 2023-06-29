#include "Animal.hpp"

Animal::Animal():_type("unknown")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type):_type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal & src):_type(src._type)
{
}

Animal & Animal::operator=(const Animal & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "* NOT RECOGNIZABLE ANIMAL SOUND *" << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}