#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	int	nbAnimals = 4;
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
	std::cout << "  1) Initializing original cat, cat1 (copy) & cat2 (copy)..." << std::endl;
	Cat	original;
	Cat	copy1(original);
	Cat	copy2 = original;
	std::cout << "  2) Checking type and sounds..." << std::endl;
	std::cout << "   - original) Type : " << original.getType() << " / Sound : ";
	original.makeSound();
	std::cout << "   - copy1) Type : " << copy1.getType() << " / Sound : ";
	copy1.makeSound();
	std::cout << "   - copy2) Type : " << copy2.getType() << " / Sound : ";
	copy2.makeSound();
	std::cout << "  3) Comparing brain's pointers of original vs. copies..." << std::endl;
	std::cout << "   - original : " << original.getBrainPointer() << std::endl;
	std::cout << "   - copy1 : " << copy1.getBrainPointer() << std::endl;
	std::cout << "   - copy2 : " << copy2.getBrainPointer() << std::endl;
	std::cout << "  4) Desctrutors..." << std::endl;

	return 0;
}