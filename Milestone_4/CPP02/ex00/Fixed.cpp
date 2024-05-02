#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0 << this->_fractBits);
}

Fixed::Fixed( const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=( const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setRawBits(copy.getRawBits());

	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits >> this->_fractBits);
}

void	Fixed::setRawBits (const int raw) {
	this->_rawBits = raw;
}
