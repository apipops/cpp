#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class	Cat: public Animal
{
private:
	Brain*	_brain;

public:
	Cat();
	Cat(const Cat & src);
	Cat & operator=(const Cat & src);
	~Cat();

	void	makeSound() const;
	Brain*	getBrainPointer() const;
};

#endif