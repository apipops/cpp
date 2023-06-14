#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap (" << name << ") constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	*this = src;
	std::cout << "ClapTrap copy constructor called." << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap (" << this->_name << ") destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_energyPoints)
		std::cout << "ClapTrap " << this->_name << " has no energy points." << std::endl;
	else 
	{
		this->_energyPoints--;
		std::cout 	<< "ClapTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout 	<< "ClapTrap " << this->_name << " takes " << amount 
					<< " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energyPoints)
		std::cout << "ClapTrap " << this->_name << " has no energy points." << std::endl;
	else 
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout 	<< "ClapTrap " << this->_name << " recovers " << amount 
					<< " hit points!" << std::endl;
	}
}
