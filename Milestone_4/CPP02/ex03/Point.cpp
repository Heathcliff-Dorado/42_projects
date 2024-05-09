#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y) {
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point( const Point& copy) : _x(copy._x), _y(copy._y) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

Point&	Point::operator=( const Point& copy) {
	//std::cout << "Point copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(Fixed) _x = copy._x;
		(Fixed) _y = copy._y;
		//std::cout << "X: " << getX() << " and copy " << copy.getX() << std::endl << "Y: " << getY() << " and copy " << copy.getY() <<std::endl;
	}
	return (*this);
}

Fixed	Point::getX( void ) const {
	return this->_x;
}

Fixed	Point::getY( void ) const {
	return (this->_y);
}

void	Point::setX( const Fixed x) {
	(Fixed) _x = x;
}

void	Point::setY( const Fixed y) {
	(Fixed) _y = y;
}
