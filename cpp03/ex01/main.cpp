#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "  > SCAVTRAP INITIALIZATION" << std::endl;
	ScavTrap	scav("Claude"); // parametric constructor called
	ScavTrap	anonymous; // default constructor called

	std::cout << std::endl << "  > TESTS WITH CLAUDE" << std::endl;
	scav.attack("Jacques");
	scav.takeDamage(50);
	scav.beRepaired(50);
	scav.guardGate(); // gate keeper mode
	scav.takeDamage(100); // dies
	scav.takeDamage(10); // already dead
	scav.beRepaired(10); // cannot repair
	scav.attack("Jacques"); // cannot attack
	scav.guardGate(); // cannot enter gate keeper mode

	std::cout << std::endl << "  > TESTS WITH [ANONYMOUS]" << std::endl;
	for (int i = 0; i < 51; i++)
	{
		std::cout << "#" << i + 1 << " ";
		anonymous.attack("someone"); // should fail at the last iteration
	}

	std::cout << std::endl;

    return 0;
}