#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog & src):Animal(src._type)
{
}

Dog & Dog::operator=(const Dog & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "'WOOF-WOOOOOF!'" << std::endl;
}