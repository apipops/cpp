#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "  > 42 TESTS" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure()); 
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "  > MATERIA TESTS (overfilling and double-equipment)" << std::endl;
	IMateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	ICharacter* john = new Character("John");
	ICharacter* mary = new Character("Mary");
	AMateria* tmp1;
	tmp1 = src1->createMateria("ice");
	john->equip(tmp1);
	john->equip(tmp1); // equip twice with same equipment
	mary->equip(tmp1); // equip someone else with same equipment
	for (int i = 0; i < 4; i++) // overfilling (already 1 + 4) > 4
	{
		tmp1 = src1->createMateria("ice");
		john->equip(tmp1);
	}
	delete src1;
	delete john;
	delete mary;
	delete tmp1;

	std::cout << std::endl << "  > UNEQUIP & ATTACK TESTS" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Cure());
	ICharacter* bill = new Character("Bill");
	AMateria* tmp2;
	tmp2 = src2->createMateria("cure");
	bill->equip(tmp2);
	ICharacter* jack = new Character("Jack");
	bill->use(0, *jack);
	bill->use(1, *jack); // use of unexisting equipment
	bill->unequip(0);
	bill->unequip(1); // unequip impossible
	delete src2;
	delete bill;
	delete jack;
	delete tmp2;

	std::cout << std::endl << "  > MATERIA SOURCE TESTS (overfilling and unknown type)" << std::endl;
	IMateriaSource* src3 = new MateriaSource();
	AMateria *tmp3;
	for (int i = 0; i < 5; i++) // filling materia source of 5 materia
	{
		tmp3 = new Ice();
		src3->learnMateria(tmp3);
	}
	AMateria *unknown = src3->createMateria("glouglou"); // create unknown type;
	std::cout << "Returm value of unknown type : " << unknown << std::endl;
	delete src3;
	delete tmp3;
	delete unknown;

	std::cout << std::endl << "  > DEEP COPY TESTS" << std::endl;
	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Cure());
	Character* simon = new Character("Simon");
	AMateria* tmp4;
	tmp4 = src4->createMateria("cure");
	simon->equip(tmp4);
	Character* simonbis = new Character(*simon); // copy assignment
	ICharacter* target = new Character("Target");
	simon->use(0, *target); 
	simonbis->use(0, *target);
	delete src4;
	delete simon;
	delete simonbis; // deleting its own materia
	delete target;
	


	return 0;
}