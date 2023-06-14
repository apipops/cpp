#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	FlagTrap : public ClapTrap
{
public:
	FlagTrap(std::string name);
 	FlagTrap(const FlagTrap & src);
	FlagTrap & operator=(const FlagTrap & src);
 	~FlagTrap();

	void 	attack(const std::string& target);
	void	highFiveGuys(void);

};

#endif