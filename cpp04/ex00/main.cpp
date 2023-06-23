#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << " > INITIALIZATION..." << std::endl;
	std::cout << "- for Animal : " << std::endl;
	const Animal* animal = new Animal();
	std::cout << "- for Dog : " << std::endl;
	const Animal* dog = new Dog();
	std::cout << "- for Cat : " << std::endl;
	const Animal* cat= new Cat();
	std::cout << "- for WrongAnimal : " << std::endl;
	const WrongAnimal* wronganimal= new WrongAnimal();
	std::cout << "- for WrongCat : " << std::endl;
	const WrongAnimal* wrongcat= new WrongCat();

	std::cout << std::endl << " > CHECHINK TYPES..." << std::endl;
	std::cout << "- for Animal : " << animal->getType() << std::endl;
	std::cout << "- for Dog : " << dog->getType() << std::endl;
	std::cout << "- for Cat : " << cat->getType() << std::endl;
	std::cout << "- for WrongAnimal : " << wronganimal->getType() << std::endl;
	std::cout << "- for WrongCat: " << wrongcat->getType() << std::endl;

	std::cout << std::endl << " > CHECHINK SOUNDS..." << std::endl;
	std::cout << "- for Animal : ";
	animal->makeSound();
	std::cout << "- for Dog : ";
	dog->makeSound();
	std::cout << "- for Cat : ";
	cat->makeSound();
	std::cout << "- for WrongAnimal : ";
	wronganimal->makeSound();
	std::cout << "- for WrongCat : ";
	wrongcat->makeSound();

	std::cout << std::endl;	
	delete animal;
	delete dog;
	delete cat;
	delete wronganimal;
	delete wrongcat;

	return 0;
}