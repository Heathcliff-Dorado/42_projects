#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	std::cout << "Ice created" << std::endl;
	setType("ice");
}

Ice::Ice( const Ice& copy) : AMateria("ice") {
	std::cout << "Ice copy created" << std::endl;
	setType("ice");
	*this = copy;
}

Ice&	Ice::operator=( const Ice& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		(void) copy;

	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice deleted" << std::endl;
}

Ice::Ice( std::string const & type ) : AMateria("ice") {
	std::cout << "Ice string created" << std::endl;
	setType("ice");
	(void) type;
}

Ice* Ice:: clone() const {
	Ice* clone = new Ice(*this);
	return (clone);
}

void Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
