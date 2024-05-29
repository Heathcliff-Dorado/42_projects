#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {
	std::cout << "ICharacter created" << std::endl;
}

ICharacter::ICharacter( const ICharacter& copy) {
	std::cout << "ICharacter copy created" << std::endl;
	*this = copy;
}

ICharacter&	ICharacter::operator=( const ICharacter& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		(void) copy;

	return (*this);
}

ICharacter::~ICharacter() {
	std::cout << "ICharacter deleted" << std::endl;
}
