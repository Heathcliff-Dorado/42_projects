#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int Integer ) : _rawBits(Integer << _fractBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float Float ) : _rawBits(roundf(Float * ( 1 << _fractBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_rawBits = (copy.getRawBits());

	return (*this);
}

bool	Fixed::operator<( const Fixed& copy ) const {
	if (_rawBits < copy._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator>( const Fixed& copy ) const {
	if (_rawBits > copy._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<=( const Fixed& copy ) const {
	if (_rawBits <= copy._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator>=( const Fixed& copy ) const {
	if (_rawBits >= copy._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator==( const Fixed& copy ) const {
	if (_rawBits == copy._rawBits)
		return (true);
	return (false);
}

bool	Fixed::operator!=( const Fixed& copy ) const {
	if (_rawBits != copy._rawBits)
		return (true);
	return (false);
}

Fixed Fixed::operator+( const Fixed& copy ) const {
	return ( Fixed( this->toFloat() + copy.toFloat() ));
}

Fixed Fixed::operator-( const Fixed& copy ) const {
	return ( Fixed( this->toFloat() - copy.toFloat() ));
}

Fixed Fixed::operator*( const Fixed& copy ) const {
	return ( Fixed( this->toFloat() * copy.toFloat() ));
}

Fixed Fixed::operator/( const Fixed& copy ) const {
	return ( Fixed( this->toFloat() / copy.toFloat() ));
}

int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits (const int raw) {
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const {
	return ( (float) (_rawBits )/ (float) ((1 << _fractBits)) );
}

int		Fixed::toInt ( void ) const {
	return (this->_rawBits >> _fractBits);
}

std::ostream& operator<<( std::ostream& o, Fixed const& i ) {
	o << i.toFloat();
	return o;
}
