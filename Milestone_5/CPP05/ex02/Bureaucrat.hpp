#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <stdexcept>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int			_grade;
public:
	Bureaucrat( void );
	Bureaucrat( const Bureaucrat& copy );
	Bureaucrat&	operator=( const Bureaucrat& copy );
	~Bureaucrat();
	Bureaucrat( std::string name, int grade);

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incrementGrade( void );
	void		decreaseGrade( void );

	void		signForm( AForm& form );
	void		executeForm( AForm const& form );
};

std::ostream& operator<<( std::ostream& o, Bureaucrat const& i );

#endif
