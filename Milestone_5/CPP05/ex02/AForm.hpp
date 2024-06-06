#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;
class AForm
{
private:
	const std::string	_name;
	const int			_gradeExecute;
	const int			_gradeSign;
	bool				_signed;
public:
	AForm( void );
	AForm( const AForm& copy );
	AForm&	operator=( const AForm& copy );
	virtual ~AForm();
	AForm( std::string name, int gradeS, int gradeE);

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

	void			beSigned( Bureaucrat& bureaucrat );
	virtual void	execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<( std::ostream& o, AForm const& i );

#endif
