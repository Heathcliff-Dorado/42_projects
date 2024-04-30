#include "Harl.hpp"

Harl::Harl ( void ) {
	std::cout << "Creating a Harl" <<std::endl;
}

Harl::~Harl ( void ) {
	std::cout << "Harl got tired of not shutting up" <<std::endl;
}
void	Harl::_debug ( void ) {
	std::cout << "I am a crybaby complaining about debug" << std::endl;
}
void	Harl::_info ( void ) {
	std::cout << "I am a crybaby complaining about info" << std::endl;
}
void	Harl::_warning ( void ) {
	std::cout << "I am a crybaby complaining about a warning" << std::endl;
}
void	Harl::_error ( void ) {
	std::cout << "I am a crybaby complaining about an error" << std::endl;
}

void	Harl::complain( std::string level ) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*message[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int	i = 4;
	for (int j = 0; j < 4; j++)
	{
		if (level == levels[j])
			i = j;
	}
	if (i < 4)
	{
		while (i < 4)
		{
			(this->*message[i])();
			i++;
		}
	}
	else
		std::cout << "Harl is insulting you between their teeth" << std::endl;
}
