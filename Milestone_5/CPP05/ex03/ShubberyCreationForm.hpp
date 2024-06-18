#ifndef SHUBBERYCREATIONFORM_H
# define SHUBBERYCREATIONFORM_H

# include "AForm.hpp"

class ShubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShubberyCreationForm( void );
		ShubberyCreationForm( const ShubberyCreationForm& copy );
		ShubberyCreationForm&	operator=( const ShubberyCreationForm& copy );
		virtual ~ShubberyCreationForm();
		ShubberyCreationForm( std::string target);

		virtual void	execute(Bureaucrat const& executor) const;
};

#endif
