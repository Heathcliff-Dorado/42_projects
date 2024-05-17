#include "Animal.hpp"

Animal::Animal( void ) : type("Unknown") {
	std::cout << "You can see an animal on the distance" << std::endl;
}

Animal::Animal( const Animal& copy) {
	std::cout << "You can see the copy of an animal on the distance" << std::endl;
	*this = copy;
}

Animal&	Animal::operator=( const Animal& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.type);

	return (*this);
}

Animal::~Animal() {
	std::cout << "The animal disappears in the distance again" << std::endl;
}

void	Animal::makeSound( void ) const{
	std::cout << "The sound of this animal is so unique it can't be described with words" << std::endl;
}

void	Animal::setType( std::string newType) {
	type = newType;
}

const std::string	Animal::getType( void ) const{
	return (type);
}
