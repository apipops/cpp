#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
 	FragTrap(const FragTrap & src);
	FragTrap & operator=(const FragTrap & src);
 	~FragTrap();

	void 	attack(const std::string& target);
	void	highFiveGuys(void);

};

#endif