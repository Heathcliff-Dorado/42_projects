#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point( void );
		Point( const Point& copy );
		Point& operator=( const Point& copy );
		~Point();

		const Fixed	getX( void );
		const Fixed	getY( void );
};

#endif
