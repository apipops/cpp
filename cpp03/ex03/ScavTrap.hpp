#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
 	ScavTrap(const ScavTrap & src);
	ScavTrap & operator=(const ScavTrap & src);
 	~ScavTrap();

	void 	attack(const std::string& target);
	void	guardGate(void);

};

#endif