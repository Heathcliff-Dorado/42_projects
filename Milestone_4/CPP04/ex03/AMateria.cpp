#include "AMateria.hpp"

AMateria::AMateria( void ) {
	std::cout << "AMateria created" << std::endl;
}

AMateria::AMateria( const AMateria& copy) {
	std::cout << "AMateria copy created" << std::endl;
	*this = copy;
}

AMateria&	AMateria::operator=( const AMateria& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		(void) copy;

	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria deleted" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
	std::cout << "AMateria string created" << std::endl;
}

std::string const& AMateria::getType() const {
	return (_type);
}

AMateria* AMateria:: clone() const {
	std::cout << "This should not be printed ever (AMateria clone)" << std::endl;
	return (NULL);
}

void AMateria::use( ICharacter& target ) {
	std::cout << "This should not be printed ever (AMateria use)" << std::endl;
	(void) target;
}

void	AMateria::setType( std::string type ) {
	_type = type;
}
