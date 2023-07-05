#include "Form.hpp"

Form::Form(std::string name, std::string target, int minSign, int minExec):
	_name(name),
	_target(target),
	_minSign(minSign),
	_minExec(minExec)
{
	this->_isSigned = false;
	if (minSign < 1 || minExec < 1)
		throw Form::GradeTooHighException();
	else if (minSign > 150 || minExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src):
	_name(src.getName()),
	_target(src.getTarget()),
	_isSigned(src.getSignStatus()),
	_minSign(src.getMinSign()),
	_minExec(src.getMinExec())
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

std::string const & Form::getTarget() const
{
	return this->_target;
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
	out << "Form " << obj.getName() << " infos: " << std::endl
		<< " - name: " << obj.getName() << std::endl
		<< " - target: " << obj.getTarget() << std::endl
		<< " - min. to sign: " << obj.getMinSign() << std::endl
		<< " - min. to execute: " << obj.getMinExec() << std::endl;
	return out;
}