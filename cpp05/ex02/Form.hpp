#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
protected:
	std::string const _name;
	bool _isSigned;
	int const _minSign;
	int const _minExec;
	std::string const _target;

	Form();

public:
	Form(std::string name, int minSign, int minExec, std::string target);
	Form(Form const &src);
	Form & operator=(Form const &src);
	virtual ~Form(); // classe de base

	std::string const & getName() const;
	int getSignStatus() const;
	int getMinSign() const;
	int getMinExec() const;
	std::string const & getTarget() const;

	void beSigned(Bureaucrat & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0; // Form class is bastract

	friend std::ostream & operator<<(std::ostream & out, Form const & obj);

	class GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

		class AlreadySignedException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

		class UnsignedForExecutionException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

#endif