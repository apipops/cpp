#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog & Dog::operator=(const Dog & src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "'WOOF-WOOOOOF!'" << std::endl;
}

Brain*	Dog::getBrainPointer() const
{
	return this->_brain;
}