#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& copy );
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm( std::string target);

		virtual void	execute(Bureaucrat const& executor) const;
};

#endif
