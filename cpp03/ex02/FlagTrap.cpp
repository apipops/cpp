#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name): ClapTrap(name) // car on doit explicitement initialiser la classe de base ClapTrap
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FlagTrap (" << name << ") constructor called." << std::endl;
}

 FlagTrap::FlagTrap(const FlagTrap & src): ClapTrap(src._name) // Vérifier pourquoi on a accès
{
	*this = src;
	std::cout << "FlagTrap copy constructor called." << std::endl;
	return ;
}

FlagTrap & FlagTrap::operator=(const FlagTrap & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "FlagTrap copy assignment operator called." << std::endl;
	return *this;
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap (" << this->_name << ") destructor called." << std::endl;
}

void	FlagTrap::attack(const std::string& target)
{
	if (!this->_energyPoints)
		std::cout << "FlagTrap " << this->_name << " has no energy points." << std::endl;
	else 
	{
		this->_energyPoints--;
		std::cout 	<< "FlagTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	FlagTrap::highFiveGuys(void)
{
	std::cout << "FlagTrap " << this->_name << " asks for a high five." << std::endl;	
}
