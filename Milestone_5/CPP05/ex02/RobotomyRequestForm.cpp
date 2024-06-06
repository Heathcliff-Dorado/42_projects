#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm copy created" << std::endl;
	*this = copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_target = copy._target;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm deleted" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Personalized RobotomyRequestForm created" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << "* DRILL NOISES *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized succesfully!" << std::endl;
	else
		std::cout << "Robotomization failed! Please collect your debris" << std::endl;
}
