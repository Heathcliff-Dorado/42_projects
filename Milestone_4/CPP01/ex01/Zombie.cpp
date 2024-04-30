#include "Zombie.hpp"


Zombie::Zombie ( void ) {

	_name = "BackgroundZ";
}

//This one is not used here, as new will use the default constructor without any parameters, and we need to assign the name with setName
// Zombie::Zombie (std::string Zname) {

// 	_name = Zname;
// }

void	Zombie::announce ( void ) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName ( std::string name) {
	_name = name;
}

Zombie::~Zombie ( void ) {

	std::cout << this->_name << " is dead for good now" <<std::endl;
}
