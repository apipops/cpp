#include "Bureaucrat.hpp"

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
		std::cout << std::endl <<  "> #1 FORM: WRONG INITIALISATION" << std::endl;
		Form wrongForm("wrong", 0, 0);
		std::cout << wrongForm;
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << "Wrong form initialization : minimum " << e.what() << std::endl;
	}

	std::cout << std::endl <<  "> #2 FORM: INSUFFICENT LEVEL" << std::endl;
	Bureaucrat bill("Bill", 101);
	std::cout << bill;
	Form form1("F1", 100, 100);
	std::cout << form1;
	bill.signForm(form1);

	std::cout << std::endl <<  "> #3 FORM: GOOD USAGE" << std::endl;
	bill.setGradeUp();
	std::cout << bill;
	std::cout << form1;
	bill.signForm(form1);

	std::cout << std::endl <<  "> #4 FORM: ALREADY SIGNED" << std::endl;
	bill.signForm(form1);

	return 0;
}