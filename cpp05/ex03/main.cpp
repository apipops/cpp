#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "---------------- INTERN TESTS----------------" << std::endl;

	std::cout << "Intern initialization..." << std::endl;
	Intern someRandomIntern;

	std::cout << std::endl << "> #1 MAKING SHRUBERRY CREATION" << std::endl;
	Form *f1;
	f1 = someRandomIntern.makeForm("shrubbery creation", "park");
	if (f1)
	{
		std::cout << *f1;
		delete f1;
	}

	std::cout << std::endl << "> #2 MAKING ROBOTOMY REQUEST" << std::endl;
	Form *f2;
	f2 = someRandomIntern.makeForm("robotomy request", "John");
	if (f2)
	{
		std::cout << *f2;
		delete f2;
	}

	std::cout << std::endl << "> #3 MAKING PRESIDENTIAL PARDON" << std::endl;
	Form *f3;
	f3 = someRandomIntern.makeForm("presidential pardon", "Mary");
	if (f3)
	{
		std::cout << *f3;
		delete f3;
	}

	std::cout << std::endl << "> #4 MAKING INVALID FORM" << std::endl;
	Form *f4;
	f4 = someRandomIntern.makeForm("invalid", "bloop");
	if (f4)
	{
		std::cout << *f4;
		delete f4;
	}



	return 0;
}