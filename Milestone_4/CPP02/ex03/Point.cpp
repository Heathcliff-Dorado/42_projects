#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y) {
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
		(Fixed)_x = copy.getX();
		(Fixed)_y = copy.getY();
	}

	return (*this);
}

Fixed	Point::getX( void ) const {
	std::cout << _x << std::endl;
	return (this->_x);
}

Fixed	Point::getY( void ) const {
	return (this->_y);
}
