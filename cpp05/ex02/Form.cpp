#include "Form.hpp"

Form::Form(std::string name, int minSign, int minExec, std::string target):
	_name(name),
	_minSign(minSign),
	_minExec(minExec),
	_target(target)
{
	this->_isSigned = false;
	if (minSign < 1 || minExec < 1)
		throw Form::GradeTooHighException();
	else if (minSign > 150 || minExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src):
	_name(src.getName()),
	_isSigned(src.getSignStatus()),
	_minSign(src.getMinSign()),
	_minExec(src.getMinExec()),
	_target(src.getTarget())
{
}

Form & Form::operator=(Form const &src)
{
	this->_isSigned = src.getSignStatus();
	return *this;
}

Form::~Form()
{
}

std::string const & Form::getName() const 
{
	return this->_name;
}

int Form::getSignStatus() const 
{
	return this->_isSigned;
}

int Form::getMinSign() const 
{
	return this->_minSign;
}

int Form::getMinExec() const 
{
	return this->_minExec;
}

std::string const & Form::getTarget() const
{
	return this->_target;
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
	if (this->_isSigned == true)
		throw Form::AlreadySignedException();
	else if (bureaucrat.getGrade() > this->_minSign)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

const char* Form::UnsignedForExecutionException::what() const throw()
{
	return ("form is unsigned");
}

std::ostream & operator<<(std::ostream & out, Form const & obj)
{
	out << "Form " << obj.getName() << ", requires " << obj.getMinSign() << " to be signed and "
		<< obj.getMinExec() << " to be executed." << std::endl;
	return out;
}