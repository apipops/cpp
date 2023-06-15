#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("[anonymous]"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap [anonymous] has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (!this->_energyPoints)
		std::cout << "ClapTrap " << this->_name << " is out of energy and cannot attack." << std::endl;
	else 
	{
		this->_energyPoints--;
		std::cout 	<< "ClapTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
	}
	else if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout 	<< "ClapTrap " << this->_name << " loses their last points and dies!"
					<< std::endl;
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
	if (!this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair." << std::endl;
	else if (!this->_energyPoints)
		std::cout << "ClapTrap " << this->_name << " is out of energy and cannot repair." << std::endl;
	else 
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout 	<< "ClapTrap " << this->_name << " recovers " << amount 
					<< " hit points!" << std::endl;
	}
}
