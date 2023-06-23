#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat & src):Animal(src._type)
{
}

Cat & Cat::operator=(const Cat & src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "'MEOOOOOW!'" << std::endl;
}