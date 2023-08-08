#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const &src);

public:
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;

};

#endif