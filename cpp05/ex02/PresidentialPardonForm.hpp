#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;

};

#endif