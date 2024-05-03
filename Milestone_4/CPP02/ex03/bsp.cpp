#include "Point.hpp"

Fixed	absolute( Fixed x ) {
	if (x < 0)
		return (x * -1);
	return (x);
}

Fixed	area( Point const a, Point const b, Point const c) {
	std::cout << "for a, getX is " << a.getX() << " and getY is " << a.getY() << std::endl;
	return (((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	realArea = absolute(area(a, b, c));
	Fixed	Area1 = absolute(area(point, b, c));
	Fixed	Area2 = absolute(area(a, point, c));
	Fixed	Area3 = absolute(area(a, b, point));

	std::cout << "Real area: " << realArea << " other areas: " << Area1 << ", " << Area2 << ", " << Area3 << std::endl;
	if (realArea == (Area1 + Area2 + Area3))
		return (true);
	return (false);
}
