#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y) {
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point( const Point& copy) : _x(copy._x), _y(copy._y) {
	//std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

Point&	Point::operator=( const Point& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(Fixed)this->_x = (const Fixed) copy.getX();
		(Fixed)this->_y = copy.getY();
	}
	return (*this);
}

Fixed	Point::getX( void ) const {
	return this->_x;
}

Fixed	Point::getY( void ) const {
	return (this->_y);
}
