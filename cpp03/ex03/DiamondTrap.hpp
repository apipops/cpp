#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <string>

class	DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
 	DiamondTrap(const DiamondTrap & src);
	DiamondTrap & operator=(const DiamondTrap & src);
 	~DiamondTrap();

	using ScavTrap::attack;
	void	whoAmI(void);

private:
	std::string	_name;
};

#endif