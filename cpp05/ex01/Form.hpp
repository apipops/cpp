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

	Form();

public:
	Form(Form const &src);
	Form & operator=(Form const &src);
	Form(std::string name, int minSign, int minExec);
	~Form();

	std::string const & getName() const;
	int getSignStatus() const;
	int getMinSign() const;
	int getMinExec() const;
	void beSigned(Bureaucrat & bureaucrat);

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
};

#endif