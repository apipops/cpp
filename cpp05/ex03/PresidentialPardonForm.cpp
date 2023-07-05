#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:Form("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	:Form("PresidentialPardonForm", src.getTarget(), 25, 5)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	this->_isSigned = src.getSignStatus();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		throw Form::UnsignedForExecutionException();
	else if (this->_minExec < executor.getGrade())
		throw Form::GradeTooLowException();
	else 
		std::cout << "Ouurahh!! " << this->_target << " has been forgiven by Zaphod Beeblebrox!" << std::endl;
}

