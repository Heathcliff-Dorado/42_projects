#include "Zombie.hpp"


Zombie::Zombie ( void ) {

	_name = "BackgroundZ";
}

Zombie::Zombie (std::string Zname) {

	_name = Zname;
}

void	Zombie::announce ( void ) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie ( void ) {

	std::cout << this->_name << " is dead for good now" <<std::endl;
}
