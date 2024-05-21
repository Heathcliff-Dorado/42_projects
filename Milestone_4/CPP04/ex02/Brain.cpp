#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain: Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "This brain is empty...";
}

Brain::Brain( const Brain& copy) {
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = copy;
}

Brain&	Brain::operator=( const Brain& copy) {
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain: Destructor called" << std::endl;
}

void	Brain::addIdea( std::string idea, int index) {
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

std::string	Brain::getIdea( int index ) {
	if (index >= 0 && index < 100)
		return(_ideas[index]);
	return (NULL);
}
