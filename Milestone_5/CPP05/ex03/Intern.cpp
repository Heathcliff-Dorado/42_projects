#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern( const Intern& copy) {
	std::cout << "Intern copy created" << std::endl;
	*this = copy;
}

Intern&	Intern::operator=( const Intern& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}

	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern deleted" << std::endl;
}

AForm*	Intern::makeForm(std::string name, std::string target) {

	int	j = 3;
	std::string	Forms[3] = {"shubbery creation", "robotomy request", "presidential pardon"};
	AForm*	form;

	for (int i = 0; i < 3; i++)
	{
		if (name == Forms[i])
			j = i;
	}
	switch (j)
	{
		case 0:
			form = new ShubberyCreationForm(target);
			return (form);
		case 1:
			form = new RobotomyRequestForm(target);
			return (form);
		case 2:
			form = new PresidentialPardonForm(target);
			return (form);
		default:
			std::cout << "This intern doesn't know how to create a " << name << " form!" <<std::endl;
			return (0);
	}
}
