#include "Point.hpp"

int	main( void ) {

	if (bsp(Point(0, 0), Point(2, 2), Point(4, 0), Point(2, 1)) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (bsp(Point(0, 0), Point(2, 2), Point(4, 0), Point(2, 2)) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (bsp(Point(0, 0), Point(2, 2), Point(4, 0), Point(-5, -10)) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}
