#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm & operator=(RobotomyRequestForm const &src);

public:
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;

};

#endif