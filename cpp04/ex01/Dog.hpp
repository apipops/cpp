#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class	Dog: public Animal
{
private:
	Brain*	_brain;

public:
	Dog();
	Dog(const Dog & src);
	Dog & operator=(const Dog & src);
	~Dog();

	void	makeSound() const;
	Brain*	getBrainPointer() const;
};

#endif