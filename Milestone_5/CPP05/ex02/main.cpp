#include "Bureaucrat.hpp"
#include "ShubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void ) {
	std::srand(time(0));
	try
	{
		Bureaucrat	first("Xi", 1);
		AForm*		form = new ShubberyCreationForm("home");

		std::cout << first << std::endl;
		std::cout << *form << std::endl;
		first.signForm(*form);
		std::cout << *form << std::endl;
		first.executeForm(*form);
		delete form;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Xi", 1);
		AForm*		form = new RobotomyRequestForm("Marvin");

		std::cout << first << std::endl;
		std::cout << *form << std::endl;
		first.signForm(*form);
		std::cout << *form << std::endl;
		first.executeForm(*form);
		first.executeForm(*form);
		first.executeForm(*form);
		first.executeForm(*form);
		first.executeForm(*form);
		first.executeForm(*form);
		first.executeForm(*form);
		first.executeForm(*form);
		delete form;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	first("Xi", 1);
		AForm*		form = new PresidentialPardonForm("Arthur");

		std::cout << first << std::endl;
		std::cout << *form << std::endl;
		first.signForm(*form);
		std::cout << *form << std::endl;
		first.executeForm(*form);
		delete form;
	}
	catch ( std::exception& e)
	{
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	// try
	// {
	// 	Bureaucrat	first("Xi", 1);
	// 	Form		form("World conquest plan", 1000, 1);

	// 	std::cout << first << std::endl;
	// 	std::cout << form << std::endl;
	// 	first.signForm(form);
	// }
	// catch ( std::exception& e)
	// {
	// 	std::cerr << "Exception found: " << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat	first("Xi", 1);
	// 	Form		form("World conquest plan", 1, 0);

	// 	std::cout << first << std::endl;
	// 	std::cout << form << std::endl;
	// 	first.signForm(form);
	// }
	// catch ( std::exception& e)
	// {
	// 	std::cerr << "Exception found: " << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat	first("Random comrade", 100);
	// 	Form		form("World conquest plan", 1, 1);

	// 	std::cout << first << std::endl;
	// 	std::cout << form << std::endl;
	// 	first.signForm(form);
	// }
	// catch ( std::exception& e)
	// {
	// 	std::cerr << "Exception found: " << e.what() << std::endl;
	// }
}
