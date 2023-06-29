#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int	nbAnimals = 4;

	//Animal test_goes_wrong; 
	// Test pour prouver que la classe est abstraite.

	std::cout << " > TAB INITIALIZATION..." << std::endl;
	Animal *animals[8];
	for (int i = 0; i < nbAnimals/2; i++)
		animals[i] = new Dog();
	for (int i = nbAnimals/2; i < nbAnimals; i++)
		animals[i] = new Cat();

	std::cout << std::endl << " > CHECHINK TYPES..." << std::endl;
	for (int i = 0; i < nbAnimals; i++)
		std::cout << "#" << i << " " << animals[i]->getType() << std::endl;

	std::cout << std::endl << " > CHECHINK SOUNDS..." << std::endl;
	for (int i = 0; i < nbAnimals; i++) {
		std::cout << "#" << i << " ";
		animals[i]->makeSound();
	}
	
	std::cout << std::endl << " > DELETING TAB..." << std::endl;
	for (int i = 0; i < nbAnimals; i++)
		delete animals[i];

	std::cout << std::endl << " > CHECKING DEEP COPYING..." << std::endl;
	std::cout << "  1) Initializing original cat and copy cat..." << std::endl;
	Cat	*original = new Cat();
	Cat	*copy = new Cat(*original);
	std::cout << "  2) Checking type and sounds..." << std::endl;
	std::cout << "   - original) Type : " << original->getType() << " / Sound : ";
	original->makeSound();
	std::cout << "   - copy) Type : " << copy->getType() << " / Sound : ";
	copy->makeSound();
	std::cout << "  3) Comparing brain's pointers of original vs. copy..." << std::endl;
	std::cout << "   - original : " << original->getBrainPointer() << std::endl;
	std::cout << "   - copy : " << copy->getBrainPointer() << std::endl;
	std::cout << "  4) Deleting..." << std::endl;
	delete original;
	delete copy;

	return 0;
}