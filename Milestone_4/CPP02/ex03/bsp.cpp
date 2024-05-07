#include "Point.hpp"

/*Fixed	absolute( Fixed x ) {
	if (x < 0)
		return (x * -1);
	return (x);
}

Fixed	area( Point const a, Point const b, Point const c) {
	return (((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	realArea(absolute(area(a, b, c)));
	Fixed	Area1(absolute(area(point, b, c)));
	Fixed	Area2(absolute(area(a, point, c)));
	Fixed	Area3(absolute(area(a, b, point)));

	if (Area1 == 0 || Area2 == 0 || Area3 == 0)
		return (false);
	if (realArea == (Area1 + Area2 + Area3))
		return (true);
	return (false);
} */

bool	IsInside(Point a, Point b, Point other, Point x) {
	//We want to find the equation Ax + By + C = 0 for the points a and b:
	Fixed A = a.getY() - b.getY();
	Fixed B = b.getX() - a.getX();
	Fixed C = a.getX() * b.getY() - a.getY() * b.getX();

	//Check if other or x are in the same line as a and b
	Fixed SolutionX = A * x.getX() + B * x.getY() + C;
	Fixed SolutionOther = A * other.getX() + B * other.getY() + C;
	if (SolutionX == 0 || SolutionOther == 0)
		return (false);
	if ((SolutionX > 0 && SolutionOther > 0) ||
		(SolutionX < 0 && SolutionOther < 0))
		return (true);
	return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	//We make a plane using two points, and check if the third and "point" are in the same side. We do this three times, following the lines a->b, b-> and c->a
	//If the three points, or "point" are in the same line, then return false, as it will not be possible to be inside of the triangle
	if(IsInside(a, b, c, point) && IsInside(b, c, a, point) && IsInside(c, a, b, point))
		return (true);
	return (false);
}
