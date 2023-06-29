#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria* _inventory[4];

	void	_delete_inventory();

public:
	Character();
	Character(std::string name);
	Character(const Character & src);
	Character & operator=(const Character & src);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};



#endif