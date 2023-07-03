#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat 
{
private:
	std::string const _name;
	int _grade;

	Bureaucrat(); // Interdire la creation d'un bureaucrate sans l'initialisation de ses attributs

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat & operator=(Bureaucrat const &src);
	~Bureaucrat();

	std::string const & getName() const;
	int getGrade() const;
	void setGradeUp();
	void setGradeDown();

	friend std::ostream & operator<<(std::ostream & out, Bureaucrat const & obj);

	class GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw() {
				return ("Grade is too high."); }
	};

	class GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw() {
				return ("Grade is too low."); }
	};
};

#endif