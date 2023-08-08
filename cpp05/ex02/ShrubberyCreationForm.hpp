#ifndef SHRUBERRYCRATIONFORM_HPP
# define SHRUBERRYCRATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
private:
	ShruberryCreationForm();
	ShruberryCreationForm(ShruberryCreationForm const &src);
	ShruberryCreationForm & operator=(ShruberryCreationForm const &src);

public:
	ShruberryCreationForm(std::string target);
	virtual ~ShruberryCreationForm();

	virtual void execute(Bureaucrat const & executor) const;

	class FileErrorException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

};

#endif