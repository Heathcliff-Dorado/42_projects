#include "Contact.hpp"

Contact::Contact( void ) {
	_index = 99;
}

Contact::~Contact() {
	if (_index != 99)
		std::cout << MAGENTA << "All data regarding " << this->_FirstName
			<< " has been deleted. Their secret has been leaked and will be used for blackmailing purposes"
			<< RESET << std::endl;
}

void	Contact::setIndex( int index) {
	_index = index;
}

void	Contact::setFN( std::string info) {
	_FirstName = info;
}

void	Contact::setLN( std::string info) {
	_LastName = info;
}

void	Contact::setNN( std::string info) {
	_NickName = info;
}

void	Contact::setPN( std::string info) {
	_PhoneNumber = info;
}

void	Contact::setDS( std::string info) {
	_Secret = info;
}

int	Contact::getIndex( void ) {
	return (_index);
}

std::string	Contact::getFN( void ) {
	return (_FirstName);
}

std::string	Contact::getLN( void ) {
	return (_LastName);
}

std::string	Contact::getNN( void ) {
	return (_NickName);
}

std::string	Contact::getPN( void ) {
	return (_PhoneNumber);
}

std::string	Contact::getDS( void ) {
	return (_Secret);
}
