#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->ClapTrap::_name += "_clap_name";
	this->_name = "[anonymous]";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = name;
 	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap " << name << " constructor called." << std::endl;
}

 DiamondTrap::DiamondTrap(const DiamondTrap & src): ClapTrap(src.ClapTrap::_name)
{
	*this = src;
	return ;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & src)
{
	this->ClapTrap::_name = src.ClapTrap::_name;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructor called." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	if (!this->_hitPoints)
		std::cout << "DiamondTrap " << this->_name << " is dead and cannot introduce himself." << std::endl;
	else
		std::cout << "DiamondTrap's names are : " << this->ClapTrap::_name << ", " << this->_name << "." << std::endl;	
}
