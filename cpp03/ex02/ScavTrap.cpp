#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) // car on doit explicitement initialiser la classe de base ClapTrap
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap (" << name << ") constructor called." << std::endl;
}

 ScavTrap::ScavTrap(const ScavTrap & src): ClapTrap(src._name) // Vérifier pourquoi on a accès
{
	*this = src;
	std::cout << "ScavTrap copy constructor called." << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap (" << this->_name << ") destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_energyPoints)
		std::cout << "ScavTrap " << this->_name << " has no energy points." << std::endl;
	else 
	{
		this->_energyPoints--;
		std::cout 	<< "ScavTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " has entered gate keeper mode." << std::endl;	
}
