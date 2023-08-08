#include "AForm.hpp"

AForm::AForm(std::string name, std::string target, int minSign, int minExec):
	_name(name),
	_target(target),
	_minSign(minSign),
	_minExec(minExec)
{
	this->_isSigned = false;
	if (minSign < 1 || minExec < 1)
		throw AForm::GradeTooHighException();
	else if (minSign > 150 || minExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

std::string const & AForm::getName() const 
{
	return this->_name;
}

std::string const & AForm::getTarget() const
{
	return this->_target;
}

int AForm::getSignStatus() const 
{
	return this->_isSigned;
}

int AForm::getMinSign() const 
{
	return this->_minSign;
}

int AForm::getMinExec() const 
{
	return this->_minExec;
}

void AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (this->_isSigned == true)
		throw AForm::AlreadySignedException();
	else if (bureaucrat.getGrade() > this->_minSign)
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

const char* AForm::UnsignedForExecutionException::what() const throw()
{
	return ("form is unsigned");
}

std::ostream & operator<<(std::ostream & out, AForm const & obj)
{
	out << "Form " << obj.getName() << " infos: " << std::endl
		<< " - name: " << obj.getName() << std::endl
		<< " - target: " << obj.getTarget() << std::endl
		<< " - min. to sign: " << obj.getMinSign() << std::endl
		<< " - min. to execute: " << obj.getMinExec() << std::endl;
	return out;
}