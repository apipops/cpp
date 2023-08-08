#include "Form.hpp"

Form::Form(std::string name, int minSign, int minExec):
	_name(name),
	_minSign(minSign),
	_minExec(minExec)
{
	this->_isSigned = false;
	if (minSign < 1 || minExec < 1)
		throw Form::GradeTooHighException();
	else if (minSign > 150 || minExec > 150)
		throw Form::GradeTooLowException();
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


std::ostream & operator<<(std::ostream & out, Form const & obj)
{
	out << "Form " << obj.getName() << ", requires " << obj.getMinSign() << " to be signed and "
		<< obj.getMinExec() << " to be executed." << std::endl;
	return out;
}