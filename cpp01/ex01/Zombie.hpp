#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
public :
	Zombie(void);
	~Zombie(void);
	void	setName(std::string name);
	void	announce(void);

private :
	std::string	_name;
};

Zombie*	zombieHorde(int n, std::string name);

#endif