#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("CogInTheMachine"), _grade(150) {
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy) : _name(copy._name) {
	std::cout << "Bureaucrat copy created" << std::endl;
	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_grade = copy._grade;
	}

	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deleted" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
	std::cout << "Personalized bureaucrat created" << std::endl;
}

std::string	Bureaucrat::getName( void ) const {
	return (_name);
}
int			Bureaucrat::getGrade( void ) const {
	return (_grade);
}
void		Bureaucrat::incrementGrade( void ) {
	if (_grade == 1)
		throw GradeTooHighException();
	else
	{
		_grade--;
		std::cout << "Congrats comrade " << _name << "! Your new grade is " << _grade << "." <<std::endl;
	}
}
void		Bureaucrat::decreaseGrade( void ) {
	if (_grade == 150)
		throw GradeTooLowException();
	else
	{
		_grade++;
		std::cout << "Shame on you, comrade " << _name << "! You've been demoted to grade " << _grade << "." <<std::endl;
	}
}

void	Bureaucrat::signForm( Form& form ) {
	if (form.isSigned() == "unsigned")
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		}
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "No one can be as good as the supreme leader! Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "No filthy human can be so despicable. Grade too low!";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";

	return o;
}
