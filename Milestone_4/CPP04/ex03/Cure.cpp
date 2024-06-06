#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	//std::cout << "Cure created" << std::endl;
	setType("cure");
}

Cure::Cure( const Cure& copy) : AMateria("cure") {
	//std::cout << "Cure copy created" << std::endl;
	setType("cure");
	*this = copy;
}

Cure&	Cure::operator=( const Cure& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		(void) copy;

	return (*this);
}

Cure::~Cure() {
	//std::cout << "Cure deleted" << std::endl;
}

Cure::Cure( std::string const & type ) : AMateria("cure") {
	//std::cout << "Cure string created" << std::endl;
	setType("cure");
	(void) type;
}

Cure* Cure:: clone() const {
	Cure* clone = new Cure(*this);
	return (clone);
}

void Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
