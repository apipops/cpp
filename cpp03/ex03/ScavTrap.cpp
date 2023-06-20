#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() // car on doit explicitement initialiser la classe de base ClapTrap
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) // car on doit explicitement initialiser la classe de base ClapTrap
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called." << std::endl;
}

 ScavTrap::ScavTrap(const ScavTrap & src): ClapTrap(src._name)
{
	*this = src;
	return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_hitPoints)
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (!this->_energyPoints)
		std::cout << "ScavTrap " << this->_name << " is out of energy and cannot attack." << std::endl;
	else 
	{
		this->_energyPoints--;
		std::cout 	<< "ScavTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (!this->_hitPoints)
		std::cout << "ScavTrap " << this->_name << " is dead and cannot enter gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " has entered gate keeper mode." << std::endl;	
}
