#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "  > SCAVTRAP INITIALIZATION" << std::endl;
	ScavTrap	scav("Claude"); // parametric constructor called
	ScavTrap	anonymous; // default constructor called

	std::cout << std::endl << "  > TESTS WITH CLAUDE" << std::endl;
	scav.attack("Jacques");
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.guardGate(); // gate keeper mode
	scav.takeDamage(10); // dies
	scav.takeDamage(10); // already dead
	scav.beRepaired(10); // cannot repair
	scav.attack("Jacques"); // cannot attack

	std::cout << std::endl << "  > TESTS WITH [ANONYMOUS]" << std::endl;
	for (int i = 0; i < 51; i++)
	{
		std::cout << "#" << i + 1 << " ";
		anonymous.attack("someone"); // should fail at the last iteration
	}

	std::cout << std::endl;

    return 0;
}