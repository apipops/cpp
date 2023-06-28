#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>
# include <iostream>

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_memory[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource & src);
	MateriaSource & operator=(const MateriaSource & src);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif