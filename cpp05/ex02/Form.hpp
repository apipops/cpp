#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
protected:
	std::string const _name;
	std::string const _target;
	bool _isSigned;
	int const _minSign;
	int const _minExec;

	Form();

public:
	Form(std::string name, std::string target, int minSign, int minExec);
	Form(Form const &src);
	Form & operator=(Form const &src);
	virtual ~Form(); // virtual destructor

	std::string const & getName() const;
	std::string const & getTarget() const;
	int getSignStatus() const;
	int getMinSign() const;
	int getMinExec() const;

	void beSigned(Bureaucrat & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0; // class From is astract

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