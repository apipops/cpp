#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat 
{
private:
	std::string const _name;
	int _grade;

	Bureaucrat();

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat & operator=(Bureaucrat const &src);
	~Bureaucrat();

	std::string const & getName() const;
	int getGrade() const;
	void setGradeUp();
	void setGradeDown();

	void signForm(Form & form);

	friend std::ostream & operator<<(std::ostream & out, Bureaucrat const & obj);

	class GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

};

#endif