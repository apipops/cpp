#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target)
	:AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShruberryCreationForm::~ShruberryCreationForm()
{
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw AForm::UnsignedForExecutionException();
	else if (this->_minExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	else 
	{
		std::ofstream	file((this->_target + "_shruberry").c_str());
		if (file.fail())
			throw ShruberryCreationForm::FileErrorException();
		file	<< "     ccee88oo\n"
				<< "  C8O8O8Q8PoOb o8oo\n"
				<< " dOB69QO8PdUOpugoO9bD\n" 
				<< "CgggbU8OU qOp qOdoUOdcb\n"
				<< "    6OuU  /p u gcoUodpP\n"
				<< "      \\\\//  /douUP\n"
				<< "        \\\\///\n"
				<< "         |||/\\\n"
				<< "         |||\\/\n"
				<< "         |||||\n"
				<< "   .....//||||\\....\n"
				<< std::endl;
	
	}
}

const char* ShruberryCreationForm::FileErrorException::what() const throw()
{
	return ("there is a file error");
}
