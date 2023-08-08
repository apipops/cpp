#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


class Base 
{
	public: virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
	int	randomNumber;
	Base *randomClass;

	std::srand(std::time(0)); // madatory to 'initialize' the random number generator
	std::cout << "Generating random class instance..." << std::endl;
	randomNumber = std::rand() % 3;

	if (randomNumber == 0)
	{
		randomClass = new A();
		std::cout << "A instance generated!" << std::endl << std::endl;

	}
	else if (randomNumber == 1)
	{
		randomClass = new B();
		std::cout << "B instance generated!" << std::endl << std::endl;

	}
	else
	{
		randomClass = new C();
		std::cout << "C instance generated!" << std::endl << std::endl;

	}
	return randomClass;
}

void identify(Base* p)
{
	std::cout << "Identifying class type from pointer..." << std::endl;
	A* a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A class identified!" << std::endl << std::endl;
		return ;
	}
	B* b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B class identified!" << std::endl << std::endl;
		return ;
	}
	C* c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "C class identified!" << std::endl << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	std::cout << "Identifying class type from reference..." << std::endl;
	try {
		A& a = dynamic_cast<A &>(p);
		std::cout << "A class identified!" << std::endl << std::endl;
		(void)a;
		return ;
	}
	catch (const std::bad_cast &e) {}
	try {
		B& b = dynamic_cast<B &>(p);
		std::cout << "B class identified!" << std::endl << std::endl;
		(void)b;
		return ;
	}
	catch (const std::bad_cast &e) {}
	try {
		C& c = dynamic_cast<C &>(p);
		std::cout << "C class identified!" << std::endl << std::endl;
		(void)c;
		return ;
	}
	catch (const std::bad_cast &e) {}
}

int main(void)
{
	Base *randomClass = generate();
	
	identify(randomClass);
	identify(*randomClass);

	delete randomClass;
	return 0;
}