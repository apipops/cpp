#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm & operator=(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;

};

#endif