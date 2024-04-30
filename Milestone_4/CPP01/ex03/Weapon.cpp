#include "Weapon.hpp"

Weapon::Weapon( void ) {
	this->_type = "Spoon";
}

Weapon::Weapon( std::string WeaponType ) {
	this->_type =WeaponType;
}

Weapon::~Weapon( void ) {
	std::cout << this->_type << " vanished from this dimension" << std::endl;
}

const std::string&	Weapon::getType( void ) {
	std::string& typeREF = this->_type;
	return (typeREF);
}

void	Weapon::setType( std::string type) {
	std::cout << this->_type << " magically turns into a " <<std::flush;
	this->_type = type;
	std::cout << this->_type << std::endl;
}
