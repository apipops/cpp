#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name),_grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src.getName())
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const & Bureaucrat::getName() const 
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGradeUp()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;

}

void Bureaucrat::setGradeDown()
{
	if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}