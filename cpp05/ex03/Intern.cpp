#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	(void)src;
}

Intern & Intern::operator=(Intern const &src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	t_function 	functions[3] = {&Intern::_makeShrubberryForm, &Intern::_makeRobotomyForm, &Intern::_makePardonForm};
	int i = 0;
	while (i < 3 && forms[i].compare(formName))
		i++;
	if (i < 3)
	{
		AForm *form;
		std::cout << "Intern creates " << formName << std::endl;
		form = (this->*functions[i])(target);
		return form;
	}
	else
		std::cout << "Intern cannot create " << formName << " because it doesn't exist"<< std::endl;
	return NULL;
}

AForm*  Intern::_makeShrubberryForm(std::string target)
{
	return new ShruberryCreationForm(target);
}

AForm* Intern::_makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::_makePardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
