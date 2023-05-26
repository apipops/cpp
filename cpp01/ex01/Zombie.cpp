#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie has been created." << std::endl;
}

Zombie::~Zombie(void) 
{
	std::cout << "Zombie '" << this->_name << "' has been destroyed." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}