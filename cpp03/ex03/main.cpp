#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "  > DIAMOND INITIALIZATION" << std::endl;
	DiamondTrap	diamond("Ruby"); // parametric constructor called
	DiamondTrap	anonymous; // default constructor called

	std::cout << std::endl << "  > TESTS WITH RUBY" << std::endl;
	diamond.attack("Sapphire");
	diamond.takeDamage(50);
	diamond.beRepaired(50);
	diamond.guardGate(); // introduction
	diamond.highFiveGuys(); // introduction
	diamond.whoAmI(); // introduction
	diamond.takeDamage(100); // dies
	diamond.takeDamage(10); // already dead
	diamond.beRepaired(10); // cannot repair
	diamond.attack("Sapphire"); // cannot attack
	diamond.whoAmI(); // cannot introduce himself

	std::cout << std::endl << "  > TESTS WITH [ANONYMOUS]" << std::endl;
	for (int i = 0; i < 51; i++)
	{
		std::cout << "#" << i + 1 << " ";
		anonymous.attack("someone"); // should fail at the last iteration
	}

	std::cout << std::endl;

    return 0;
}