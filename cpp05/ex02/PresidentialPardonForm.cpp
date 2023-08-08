#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw AForm::UnsignedForExecutionException();
	else if (this->_minExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	else 
		std::cout << "Ouurahh!! " << this->_target << " has been forgiven by Zaphod Beeblebrox!" << std::endl;
}

