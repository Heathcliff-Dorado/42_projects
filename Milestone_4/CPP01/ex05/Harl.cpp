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
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*message[i])();
	}
}
