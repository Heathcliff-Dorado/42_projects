#include "ShubberyCreationForm.hpp"

ShubberyCreationForm::ShubberyCreationForm( void ) : AForm("ShubberyCreationForm", 145, 137), _target("default") {
	std::cout << "ShubberyCreationForm created" << std::endl;
}

ShubberyCreationForm::ShubberyCreationForm( const ShubberyCreationForm& copy) : AForm("ShubberyCreationForm", 145, 137) {
	std::cout << "ShubberyCreationForm copy created" << std::endl;
	*this = copy;
}

ShubberyCreationForm&	ShubberyCreationForm::operator=( const ShubberyCreationForm& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_target = copy._target;
	}

	return (*this);
}

ShubberyCreationForm::~ShubberyCreationForm() {
	std::cout << "ShubberyCreationForm deleted" << std::endl;
}

ShubberyCreationForm::ShubberyCreationForm( std::string target ) : AForm("ShubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Personalized ShubberyCreationForm created" << std::endl;
}

void	ShubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::ofstream	output((_target + "_shubbery").c_str());
	if (!output)
	{
		std::cout << "Error creating the " << _target << "_shubbery file" <<std::endl;
	}
	else
	{
		output << "          &&& &&  & &&" << std::endl;
		output << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		output << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		output << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
		output << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		output << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		output << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		output << "     &&    \\|||" << std::endl;
		output << "             |||" << std::endl;
		output << "             |||" << std::endl;
		output << "             |||" << std::endl;
		output << "       , -=-~  .-^- _" << std::endl;
		output.close();
	}

}
