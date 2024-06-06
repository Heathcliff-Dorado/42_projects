#include "AForm.hpp"

AForm::AForm( void ) : _name("StandardForm"), _gradeExecute(150), _gradeSign(150), _signed(false) {
	std::cout << "AForm created" << std::endl;
}

AForm::AForm( const AForm& copy) : _name(copy._name), _gradeExecute(copy._gradeExecute), _gradeSign(copy._gradeSign) {
	std::cout << "AForm copy created" << std::endl;
	*this = copy;
}

AForm&	AForm::operator=( const AForm& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_signed = copy._signed;
	}

	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm deleted" << std::endl;
}

AForm::AForm( std::string name, int gradeS, int gradeE ) : _name(name), _gradeExecute(gradeE), _gradeSign(gradeS) {
	if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
	else if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
	else
		_signed = false;
	std::cout << "Personalized AForm created" << std::endl;
}

std::string	AForm::getName( void ) const {
	return (_name);

}
int			AForm::getGradeSign( void ) const {
	return (_gradeSign);
}

int			AForm::getGradeExecute( void ) const {
	return (_gradeExecute);
}

std::string	AForm::isSigned( void ) const {
	if (_signed)
		return ("signed");
	else
		return ("unsigned");
}

void		AForm::beSigned( Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > _gradeExecute)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "A form so pure no one can use it cannot exist. The required grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "A non-worthy bureaucrat tried touching this masterpiece. Or, this document allows unworthy bureaucrats to use it. Grade too low";
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "Form name: " << i.getName() << " requires grade " << i.getGradeSign() << " for a signature and grade " << i.getGradeExecute() << " to be executed. The form is " << i.isSigned();

	return o;
}
