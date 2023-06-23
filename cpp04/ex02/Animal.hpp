#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal & src);
	Animal & operator=(const Animal & src);
	virtual ~Animal();

	virtual void	makeSound() const = 0; // '= 0' makes the class abstract
	std::string			getType() const;
};

#endif