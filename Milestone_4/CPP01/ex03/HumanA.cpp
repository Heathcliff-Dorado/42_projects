#include "HumanA.hpp"

// HumanA::HumanA( void ) {
// 	Weapon	weapon;
// 	_name = "Dude";
// 	_weapon = weapon;
// }

HumanA::HumanA(std::string name, Weapon& weapon): _name (name), _weapon(weapon)
{
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " died unexpectedly" <<std::endl;
}

void	HumanA::attack( void ) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon2) {
	_weapon = weapon2;
	std::cout << this->_name << " is now holding a " << this->_weapon.getType() << std::endl;
}
