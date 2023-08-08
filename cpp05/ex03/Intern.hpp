#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern 
{
public:
	Intern();
	Intern(Intern const &src);
	Intern & operator=(Intern const &src);
	~Intern();

	AForm* makeForm(std::string formName, std::string target);

private:
	AForm* _makeShrubberryForm(std::string target);
	AForm* _makeRobotomyForm(std::string target);
	AForm* _makePardonForm(std::string target);
};

typedef	AForm*	(Intern::*t_function)(std::string target);

#endif