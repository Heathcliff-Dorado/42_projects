#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Now you can clearly distinguish a cat!" << std::endl;
	_brain = new Brain;
	type = "Cat";
}

Cat::Cat( const Cat& copy) : Animal(copy) {
	std::cout << "It is now clear that it's the copy of a cat!" << std::endl;
	*this = copy;
}

Cat&	Cat::operator=( const Cat& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete _brain;
		_brain = copy._brain;
		this->setType(copy.type);
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "The cat ran away" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Cat: Meow meow, you motherfucker" << std::endl;
}
