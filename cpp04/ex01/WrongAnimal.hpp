#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal & src);
	WrongAnimal & operator=(const WrongAnimal & src);
	~WrongAnimal(); // no virtual

	void	makeSound() const; // no virtual
	std::string			getType() const;
};

#endif