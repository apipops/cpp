#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap("Jim"); // parametric constructor called
	ClapTrap	anonymous; // default constructor called

	clap.attack("Bob");
	clap.takeDamage(5);
	clap.beRepaired(5);
	clap.takeDamage(10); // dies
	clap.takeDamage(10); // already dead
	clap.beRepaired(10); // cannot repair
	clap.attack("Bob"); // cannot attack

	for (int i = 0; i < 11; i++)
		anonymous.attack("someone"); // last iteration should fail
}