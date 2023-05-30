#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):_name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their weapon " << this->_weapon.getType() << std::endl;
}

#endif