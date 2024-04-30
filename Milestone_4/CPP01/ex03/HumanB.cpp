#include "HumanB.hpp"

// HumanB::HumanB( void ) {
// 	_name = "Dude";
// }

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " died unexpectedly" <<std::endl;
}

void	HumanB::attack( void ) {
	if (_weapon == NULL)
		std::cout << this->_name << " is unarmed and can't attack!" <<std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon2) {
	_weapon = &weapon2;
	std::cout << this->_name << " is now holding a " << this->_weapon->getType() << std::endl;
}
