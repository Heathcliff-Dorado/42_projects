#include "Bureaucrat.hpp"

int	main( void ) {
	try
	{
		Bureaucrat	first;
		Bureaucrat	second(first);

		std::cout << first << std::endl;
		std::cout << second << std::endl;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Stalin", 0);

		std::cout << first << std::endl;
		first.decreaseGrade();
		std::cout << first << std::endl;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	second("Uncle Sam", 160);

		std::cout << second << std::endl;
		second.incrementGrade();
		std::cout << second << std::endl;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Stalin", 1);
		Bureaucrat	second("Uncle Sam", 150);

		std::cout << first << std::endl;
		first.decreaseGrade();
		std::cout << first << std::endl;
		std::cout << second << std::endl;
		second.incrementGrade();
		std::cout << second << std::endl;
		first.incrementGrade();
		first.incrementGrade();
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
}
