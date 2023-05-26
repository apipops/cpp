#include "Zombie.hpp"

Zombie::Zombie(std::string name):_name(name) 
{
	std::cout << "Zombie '" << this->_name << "' has been created." << std::endl;
}

Zombie::~Zombie(void) 
{
	std::cout << "Zombie '" << this->_name << "' has been destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}