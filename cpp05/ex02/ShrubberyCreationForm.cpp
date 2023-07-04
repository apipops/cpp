#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target)
	:Form("ShrubberyCreationForm", 145, 137, target)
{
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const &src)
	:Form("ShrubberyCreationForm", 145, 137, src.getTarget())
{
}

ShruberryCreationForm & ShruberryCreationForm::operator=(ShruberryCreationForm const &src)
{
	this->_isSigned = src.getSignStatus();
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm()
{
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	
}


#endif