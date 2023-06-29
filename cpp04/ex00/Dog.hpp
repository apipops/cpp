#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class	Dog: public Animal
{
public:
	Dog();
	Dog(const Dog & src);
	Dog & operator=(const Dog & src);
	virtual ~Dog();

	virtual void	makeSound() const;
};

#endif