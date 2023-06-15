#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "  > FRAGTRAP INITIALIZATION" << std::endl;
	FragTrap	frag("Jane"); // parametric constructor called
	FragTrap	anonymous; // default constructor called

	std::cout << std::endl << "  > TESTS WITH JANE" << std::endl;
	frag.attack("Tarzan");
	frag.takeDamage(50);
	frag.beRepaired(50);
	frag.highFiveGuys(); // high five
	frag.takeDamage(100); // dies
	frag.takeDamage(10); // already dead
	frag.beRepaired(10); // cannot repair
	frag.attack("Tarzan"); // cannot attack
	frag.highFiveGuys(); // cannot ask for high five

	std::cout << std::endl << "  > TESTS WITH [ANONYMOUS]" << std::endl;
	for (int i = 0; i < 101; i++)
	{
		std::cout << "#" << i + 1 << " ";
		anonymous.attack("someone"); // should fail at the last iteration
	}

	std::cout << std::endl;

    return 0;
}