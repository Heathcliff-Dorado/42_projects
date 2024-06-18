#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& copy );
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm( std::string target);

		virtual void	execute(Bureaucrat const& executor) const;
};

#endif
