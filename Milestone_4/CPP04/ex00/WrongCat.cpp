#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "Looks like a cat? But something is off..." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "It's the creepiest cat-like creature that I've ever seen!" << std::endl;
	*this = copy;
}

WrongCat&	WrongCat::operator=( const WrongCat& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.type);

	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "The cat looks through you as if you weren't there" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "WrongCat: Woof Woof, oh wait..." << std::endl;
}
