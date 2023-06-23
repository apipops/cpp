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
	virtual ~WrongAnimal(); // virtual or not : destructor called for WrongCat ?

	void	makeSound() const; // no virtual
	std::string			getType() const;
};

#endif