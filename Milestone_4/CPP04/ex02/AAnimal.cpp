#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("Unknown") {
	std::cout << "You can see an animal on the distance" << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy) {
	std::cout << "You can see the copy of an animal on the distance" << std::endl;
	*this = copy;
}

AAnimal&	AAnimal::operator=( const AAnimal& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.type);

	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "The animal disappears in the distance again" << std::endl;
}

void	AAnimal::makeSound( void ) const{
	std::cout << "The sound of this animal is so unique it can't be described with words" << std::endl;
}

void	AAnimal::setType( std::string newType) {
	type = newType;
}

const std::string	AAnimal::getType( void ) const{
	return (type);
}

void	AAnimal::setIdea( std::string idea, int index) {
	(void) idea;
	(void) index;
	std::cout << "I have no brain to store ideas" << std::endl;
}

void	AAnimal::printIdea( int index) {
	(void) index;
	std::cout << "There are no ideas in me" << std::endl;
}
