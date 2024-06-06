#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_gradeExecute;
	const int			_gradeSign;
	bool				_signed;
public:
	Form( void );
	Form( const Form& copy );
	Form&	operator=( const Form& copy );
	~Form();
	Form( std::string name, int gradeS, int gradeE);

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	std::string	getName( void ) const;
	int			getGradeSign( void ) const;
	int			getGradeExecute( void ) const;
	std::string	isSigned( void ) const;

	void		beSigned( Bureaucrat& bureaucrat );
};

std::ostream& operator<<( std::ostream& o, Form const& i );

#endif
