#include "Character.hpp"

Character::Character():_name("unknown")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name):_name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character & src)
{
	*this = src;
}

Character & Character::operator=(const Character & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++) // supprimer l'ancien inventory
		{
			if (this->_inventory[i]) 
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++) // remplacer par le nouvel inventory
		{
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Materia does not exist." << std::endl;
		return;
	}
	else if (m->getTakenStatus())
	{
		std::cout << "Materia "<< m->getType() << " is already taken. Character " << this->getName() << " cannot equip." << std::endl;
		return ;
	}
	int	nbMateria = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			m->setTakenStatus(TAKEN);
			//std::cout << "Character " << this->_name << " has been equiped with " << m->getType() << std::endl;
			break ;
		}
		else
			nbMateria++;
	}
	if (nbMateria == 4)
		std::cout << "Character " << this->_name << " has a full inventory and cannot be equiped with " << m->getType() << "." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		std::cout << "Character " << this->_name << " has no equipment at slot " << idx << "." << std::endl;
	else
	{
		this->_inventory[idx]->setTakenStatus(ON_FLOOR);
		this->_inventory[idx] = NULL;
		// std::cout << "Character " << this->_name << " has been unequiped of materia #" << idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		std::cout << "Character " << this->_name << " has no equipment at slot " << idx << "." << std::endl;
	else
		this->_inventory[idx]->use(target);
}
