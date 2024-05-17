#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Now you can clearly distinguish a dog!" << std::endl;
	_brain = new Brain;
	type = "Dog";
}

Dog::Dog( const Dog& copy) : Animal(copy) {
	std::cout << "It is now clear that it's the copy of a dog!" << std::endl;
	*this = copy;
}

Dog&	Dog::operator=( const Dog& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete _brain;
		_brain = copy._brain;
		this->setType(copy.type);
	}
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "The dog heard the distant sound of food" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Dog: Woof woof (you can see the emptiness of their brain)" << std::endl;
}
