#ifndef SHRUBERRYCRATIONFORM_HPP
# define SHRUBERRYCRATIONFORM_HPP

# include "Form.hpp"

class ShruberryCreationForm : public Form
{
private:
	ShruberryCreationForm();

public:
	ShruberryCreationForm(std::string target);
	ShruberryCreationForm(ShruberryCreationForm const &src);
	ShruberryCreationForm & operator=(ShruberryCreationForm const &src);
	virtual ~ShruberryCreationForm();

	virtual void execute(Bureaucrat const & executor) const;

};

#endif