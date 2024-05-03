#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point( const Point& copy) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

Point&	Point::operator=( const Point& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_x = (const Fixed) copy.getX();
		this->_y = (const Fixed) copy.getY();
	}

	return (*this);
}

const Fixed	Point::getX( void ) const {
	return (this->_x);
}
