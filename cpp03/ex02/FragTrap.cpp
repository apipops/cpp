#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() // car on doit explicitement initialiser la classe de base ClapTrap
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) // car on doit explicitement initialiser la classe de base ClapTrap
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called." << std::endl;
}

 FragTrap::FragTrap(const FragTrap & src): ClapTrap(src._name)
{
	*this = src;
	return ;
}

FragTrap & FragTrap::operator=(const FragTrap & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->_hitPoints)
		std::cout << "FragTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (!this->_energyPoints)
		std::cout << "FragTrap " << this->_name << " is out of energy and cannot attack." << std::endl;
	else 
	{
		this->_energyPoints--;
		std::cout 	<< "FragTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFiveGuys(void)
{
	if (!this->_hitPoints)
		std::cout << "FragTrap " << this->_name << " is dead and cannot ask for a high five." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " asks for a high five." << std::endl;	
}
