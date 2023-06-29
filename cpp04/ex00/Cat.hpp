#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class	Cat: public Animal
{
public:
	Cat();
	Cat(const Cat & src);
	Cat & operator=(const Cat & src);
	virtual ~Cat();

	virtual void	makeSound() const;
};

#endif