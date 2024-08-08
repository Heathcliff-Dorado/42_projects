#include "Template.hpp"

int	main(void)
{
	int	a = 40;
	int	b = 38;

	std::cout << "a is " << a << ", b is " << b << " and min is " << ::min(a, b) << std::endl;
	std::cout << "a is " << a << ", b is " << b << " and max is " << ::max(a, b) << std::endl;
	std::cout << "a is " << a << ", b is " << b << " and after swap ";
	::swap(a, b);
	std::cout << "a is " << a << ", b is " << b << std::endl;

	std::string	c = "string1";
	std::string	d = "string2";

	std::cout << "c is " << c << ", d is " << d << " and min is " << ::min(c, d) << std::endl;
	std::cout << "c is " << c << ", d is " << d << " and max is " << ::max(c, d) << std::endl;
	std::cout << "c is " << c << ", d is " << d << " and after swap ";
	::swap(c, d);
	std::cout << "c is " << c << ", d is " << d << std::endl;
}
