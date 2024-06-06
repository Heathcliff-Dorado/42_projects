#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy) : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm copy created" << std::endl;
	*this = copy;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_target = copy._target;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm deleted" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Personalized PresidentialPardonForm created" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
