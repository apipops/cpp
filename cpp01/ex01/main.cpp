#include "Zombie.hpp"

int	main(void)
{
	// Initialisation params zombies
	int nb = 10;
	std::string name = "Bob";

	// Allocation de la horde de zombie dans la heap
	std::cout << "Calling function 'zombieHorde'..." << std::endl;
	Zombie *horde = zombieHorde(nb, name);

	// Appel de la fonction announce()
	std::cout << std::endl << "Calling member function 'announce'..." << std::endl;
	for (int i = 0; i < nb; i++)
	{
		std::cout << "#" << i << " ";
		horde[i].announce();
	}

	// Destruction de la horde
	std::cout << std::endl << "Destruction of the horde..." << std::endl;
	delete [] horde;

	return (0);
}