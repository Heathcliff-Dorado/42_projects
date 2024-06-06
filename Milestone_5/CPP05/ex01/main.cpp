#include "Bureaucrat.hpp"

int	main( void ) {
	try
	{
		Bureaucrat	first("Xi", 1);
		Form		form("World conquest plan", 1, 1);

		std::cout << first << std::endl;
		std::cout << form << std::endl;
		first.signForm(form);
		std::cout << form << std::endl;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Xi", 1);
		Form		form("World conquest plan", 1000, 1);

		std::cout << first << std::endl;
		std::cout << form << std::endl;
		first.signForm(form);
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Xi", 1);
		Form		form("World conquest plan", 1, 0);

		std::cout << first << std::endl;
		std::cout << form << std::endl;
		first.signForm(form);
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Random comrade", 100);
		Form		form("World conquest plan", 1, 1);

		std::cout << first << std::endl;
		std::cout << form << std::endl;
		first.signForm(form);
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
}
