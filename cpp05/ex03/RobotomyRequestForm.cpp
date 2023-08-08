#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw AForm::UnsignedForExecutionException();
	else if (this->_minExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	else 
	{
		std::cout << "BBBBbbbbrrrrrrzzzzzzzzzzzz!!!!! ";
		std::srand(std::time(0));
		if (std::rand() % 2)
			std::cout << this->_target << " has been successfully robotomized!" << std::endl;
		else
			std::cout << "Robotomy operation has failed for " << this->_target << "!" << std::endl;
	}
}

