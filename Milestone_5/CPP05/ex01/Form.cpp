#include "Form.hpp"

Form::Form( void ) : _name("StandardForm"), _gradeExecute(150), _gradeSign(150), _signed(false) {
	std::cout << "Form created" << std::endl;
}

Form::Form( const Form& copy) : _name(copy._name), _gradeExecute(copy._gradeExecute), _gradeSign(copy._gradeSign) {
	std::cout << "Form copy created" << std::endl;
	*this = copy;
}

Form&	Form::operator=( const Form& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_signed = copy._signed;
	}

	return (*this);
}

Form::~Form() {
	std::cout << "Form deleted" << std::endl;
}

Form::Form( std::string name, int gradeS, int gradeE ) : _name(name), _gradeExecute(gradeE), _gradeSign(gradeS) {
	if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
	else if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
	else
		_signed = false;
	std::cout << "Personalized form created" << std::endl;
}

std::string	Form::getName( void ) const {
	return (_name);

}
int			Form::getGradeSign( void ) const {
	return (_gradeSign);
}

int			Form::getGradeExecute( void ) const {
	return (_gradeExecute);
}

std::string	Form::isSigned( void ) const {
	if (_signed)
		return ("signed");
	else
		return ("unsigned");
}

void		Form::beSigned( Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "A form so pure no one can use it cannot exist. The required grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "A non-worthy bureaucrat tried touching this masterpiece. Or, this document allows unworthy bureaucrats to use it. Grade too low";
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form name: " << i.getName() << " requires grade " << i.getGradeSign() << " for a signature and grade " << i.getGradeExecute() << " to be executed. The form is " << i.isSigned();

	return o;
}
