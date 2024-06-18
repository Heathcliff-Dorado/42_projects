#ifndef INTERN_H
# define INTERN_H

#include "ShubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern( void );
	Intern( const Intern& copy );
	Intern&	operator=( const Intern& copy );
	~Intern();

	AForm*	makeForm(std::string name, std::string target);
};

#endif
