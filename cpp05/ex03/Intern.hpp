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

	Form* makeForm(std::string formName, std::string target);

private:
	Form* _makeShrubberryForm(std::string target);
	Form* _makeRobotomyForm(std::string target);
	Form* _makePardonForm(std::string target);
};

typedef	Form*	(Intern::*t_function)(std::string target);

#endif