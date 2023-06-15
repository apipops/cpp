#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Calling function 'newZombie' for Rose..." << std::endl;
	// Allocation du zombie Rose dans la heap
	Zombie *rose = newZombie("Rose");

	// Allocation du zombie Jack dans la stack
	// dans le scope de la fonction
	std::cout << "Calling function 'randomChump' for Jack..." << std::endl;
	randomChump("Jack");

	rose->announce(); // Rose existe en dehors de sa fonction de création
	delete rose; // Destructeur appelé seulement à la libération de la mémoire

	return (0);
}