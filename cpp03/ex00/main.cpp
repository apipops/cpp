#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "  > CLAPTRAP INITIALIZATION" << std::endl;
	ClapTrap	clap("Jim"); // parametric constructor called
	ClapTrap	anonymous; // default constructor called

	std::cout << std::endl << "  > TESTS WITH JIM" << std::endl;
	clap.attack("Bob");
	clap.takeDamage(5);
	clap.beRepaired(5);
	clap.takeDamage(10); // dies
	clap.takeDamage(10); // already dead
	clap.beRepaired(10); // cannot repair
	clap.attack("Bob"); // cannot attack

	std::cout << std::endl << "  > TESTS WITH [ANONYMOUS]" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "#" << i + 1 << " ";
		anonymous.attack("someone"); // should fail at the last iteration
	}

	std::cout << std::endl;
}