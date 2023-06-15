#include "Weapon.hpp"

class	HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);
	void	attack(void) const;
	void	setWeapon(Weapon &weapon);

private:
	std::string	_name;
	Weapon*		_weapon;
};
