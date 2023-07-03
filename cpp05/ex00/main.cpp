#include "Bureaucrat.hpp"

int main()
{
/* 	Bureaucrat	tooLow("Low", 151);
	Bureaucrat	bob("Bob", 151); */

	try
	{
		std::cout << "> #1 WRONG INITIALISATION : TOO HIGH" << std::endl;
		Bureaucrat	tooHigh("High", 0);
		std::cout << tooHigh;
		tooHigh.setGradeDown();
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
		std::cout << std::endl << "> #2 WRONG INITIALISATION : TOO LOW" << std::endl;
		Bureaucrat	tooLow("Low", 151);
		std::cout << tooLow;
		tooLow.setGradeUp();
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
		std::cout << std::endl << "> #3 GOOD INITIALIZATION BUT WRONG INCREMENT" << std::endl;
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
		std::cout << std::endl << "> #4 GOOD INITIALIZATION BUT WRONG DECREMENT" << std::endl;
		Bureaucrat	wrongDecrement("Bill", 150);
		std::cout << wrongDecrement;
		wrongDecrement.setGradeDown();
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
		std::cout << std::endl << "> #5 GOOD BUREAUCRAT" << std::endl;
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
	

	return 0;
}