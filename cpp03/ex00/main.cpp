#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap("Jim");

	clap.attack("Bob");
	clap.takeDamage(5);
	clap.beRepaired(5);
	clap.takeDamage(10);
	clap.beRepaired(10); // 3 energy points lost so far.

	for (int i = 0; i < 8; i++)
		clap.attack("Bob"); // last iteration should fail
}