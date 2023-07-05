#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "---------------- BUREAUCRAT TESTS----------------" << std::endl;
	try
	{
		std::cout << std::endl << "> #1 BUREAUCRAT: WRONG INITIALISATION" << std::endl;
		Bureaucrat	wrongBureaucrat("wrong", 0); // idem si on initialise a 151
		std::cout << wrongBureaucrat;
		wrongBureaucrat.setGradeDown();
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "> #2 BUREAUCRAT: WRONG INCREMENT" << std::endl;
		Bureaucrat	wrongIncrement("Bob", 1);
		std::cout << wrongIncrement;
		wrongIncrement.setGradeUp();
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "> #3 BUREAUCRAT: GOOD USAGE" << std::endl;
		Bureaucrat	good("Sam", 5);
		std::cout << good;
		good.setGradeDown();
		std::cout << good;
		good.setGradeDown();
		std::cout << good;
		good.setGradeUp();
		std::cout << good;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------------- FORM TESTS----------------" << std::endl;

	try
	{
		std::cout << std::endl <<  "> #1 SHRUBERRY CREATION FORM" << std::endl;
		ShruberryCreationForm shruberryForm("garden");
		std::cout << shruberryForm;
		Bureaucrat mark("Mark", 50);
		std::cout << mark;
		mark.executeForm(shruberryForm);
		mark.signForm(shruberryForm);
		mark.executeForm(shruberryForm);
		
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl <<  "> #2 ROBOTOMY REQUEST FORM" << std::endl;
		RobotomyRequestForm robotomyForm("James");
		std::cout << robotomyForm;
		Bureaucrat britney("Britney", 30);
		std::cout << britney;
		britney.signForm(robotomyForm);
		britney.executeForm(robotomyForm);
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl <<  "> #3 PRESIDENTIAL PARDON FORM" << std::endl;
		PresidentialPardonForm pardonForm("Karl");
		std::cout << pardonForm;;
		Bureaucrat jane("Jane", 5);
		std::cout << jane;
		jane.signForm(pardonForm);
		jane.executeForm(pardonForm);
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}


	return 0;
}