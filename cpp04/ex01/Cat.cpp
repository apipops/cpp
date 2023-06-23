#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat & src):Animal(src._type)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat & Cat::operator=(const Cat & src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "'MEOOOOOW!'" << std::endl;
}

Brain*	Cat::getBrainPointer() const
{
	return this->_brain;
}