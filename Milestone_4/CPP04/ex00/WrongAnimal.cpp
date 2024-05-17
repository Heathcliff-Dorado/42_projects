#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("Unknown") {
	std::cout << "Some strange animal eats some psychodelic substance" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy) {
	std::cout << "From the distance there's a copy of an animal that looks high af" << std::endl;
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.type);

	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "The animal trascended from this dimension" << std::endl;
}

void	WrongAnimal::makeSound( void ) const{
	std::cout << "The animal is so high that has become nonverbal" << std::endl;
}

void	WrongAnimal::setType( std::string newType) {
	type = newType;
}

const std::string	WrongAnimal::getType( void ) const{
	return (type);
}
