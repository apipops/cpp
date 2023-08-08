#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	std::string const _name;
	std::string const _target;
	bool _isSigned;
	int const _minSign;
	int const _minExec;

	AForm();
	AForm(AForm const &src);
	AForm & operator=(AForm const &src);

public:
	AForm(std::string name, std::string target, int minSign, int minExec);
	virtual ~AForm(); // virtual destructor

	std::string const & getName() const;
	std::string const & getTarget() const;
	int getSignStatus() const;
	int getMinSign() const;
	int getMinExec() const;

	void beSigned(Bureaucrat & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0; // AFrom is astract

	friend std::ostream & operator<<(std::ostream & out, AForm const & obj);

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