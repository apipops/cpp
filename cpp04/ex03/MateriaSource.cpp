#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
	// std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource & src)
{
	*this = src;
	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src)
{
	for (int i = 0; i < 4; i++)
	{
		if (!src._memory[i])
			break;
		this->_memory[i] = src._memory[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i])
			delete this->_memory[i];
	}
	// std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while (i < 4 && this->_memory[i])
		i++;
	if (i == 4)
		std::cout << "MateriaSource is full" << std::endl;
	else
		this->_memory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && this->_memory[i] && this->_memory[i]->getType() != type)
		i++;
	if (i == 4 || !this->_memory[i])
		return (NULL);
	else
		return (this->_memory[i]->clone());
};
