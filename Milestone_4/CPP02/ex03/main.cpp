#include "Point.hpp"

int	main( void ) {
	Point	a(0, 0);
	Point	b(2, 2);
	Point	c(4, 0);
	Point	point(2, 1);

	if (bsp(a, b, c, point) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	Point	point2(2, 2);

	if (bsp(a, b, c, point2) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	Point	point3(-5, -10);

	if (bsp(a, b, c, point3) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}
