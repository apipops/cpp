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

	virtual void	makeSound() const; // keyword 'virtual' makes the compiler free the memory of derived classes first
	std::string			getType() const;
};

#endif