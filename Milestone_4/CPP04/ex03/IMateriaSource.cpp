#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void ) {
	//std::cout << "IMateria source created" << std::endl;
}

IMateriaSource::IMateriaSource( const IMateriaSource& copy) {
	//std::cout << "IMateria source copy created" << std::endl;
	*this = copy;
}

IMateriaSource&	IMateriaSource::operator=( const IMateriaSource& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		(void) copy;

	return (*this);
}

IMateriaSource::~IMateriaSource() {
	//std::cout << "IMateria source deleted" << std::endl;
}
