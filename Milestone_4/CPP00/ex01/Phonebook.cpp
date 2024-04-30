#include "Phonebook.hpp"

Phonebook::Phonebook( void ) {
	_ncontacts = 0;
	_nextIndex = 0;
}

Phonebook::~Phonebook( void ) {
	std::cout << CYAN << "Thanks for using the Phonebook! Don't forget to tip :D" << RESET << std::endl;
}

std::string	Phonebook::truncate( std::string info) {
	if (info.size() > 10)
	{
		info = info.substr(0, 9);
		info.push_back('.');
	}
	return (info);
}

void	Phonebook::WelcomeMessage( void ) {
	std::cout << CYAN << "Welcome to the phonebook! This is an old relic from before smartphones, "
		<< "when there was no social media and people only knew up to 8 other persons." << std::endl;
	std::cout << "Please follow these instructions, I will ignore anything else, and customer service does not exist:" << std::endl;
	std::cout << "Type ADD if you wish to add a new contact" << std::endl;
	std::cout << "Type SEARCH if you wish to look for a specific contact already saved" << std::endl;
	std::cout << "Type EXIT if you are finished using me" << RESET << std::endl;
}

void	Phonebook::AddContact( void ) {
	std::string	input;

	if (_nextIndex == 8)
	{
		std::cout << RED << "You know too many people! The oldest one will be deleted" << RESET << std::endl;
		_nextIndex = 0;
	}
	if (_ncontacts < 8)
		_ncontacts++;
	_contact[_nextIndex].setIndex(_nextIndex);
	std::cout << YELLOW << "Please, provide their first name: "  << RESET;
	std::getline(std::cin, input);
	_contact[_nextIndex].setFN(input);
	std::cout << YELLOW << "Please, provide their last name: " << RESET;
	std::getline(std::cin, input);
	_contact[_nextIndex].setLN(input);
	std::cout << YELLOW << "Please, provide their nickname: " << RESET;
	std::getline(std::cin, input);
	_contact[_nextIndex].setNN(input);
	std::cout << YELLOW << "Please, provide their phone number: " << RESET;
	std::getline(std::cin, input);
	_contact[_nextIndex].setPN(input);
	std::cout << YELLOW << "Please, provide their darkest secret: " << RESET;
	std::getline(std::cin, input);
	_contact[_nextIndex].setDS(input);
	std::cout << GREEN << "Thank you for trusting us with this information."
		<< " You will be redirected to the beginning of this Phonebook" << RESET << std::endl;
	_nextIndex++;
	WelcomeMessage();
}

bool	Phonebook::isValid( std::string input ) {
	if (input.size() != 1)
		return false;
	if (isdigit((int) input[0]) && std::atoi(input.c_str()) < _ncontacts)
		return true;
	return false;
}

void	Phonebook::SearchContact( void ) {
	std::string	input;

	if (_ncontacts == 0)
	{
		std::cout << RED << "No contacts stored yet!" << RESET << std::endl;
		WelcomeMessage();
	}
	else
	{
		std::cout << CYAN << "Please indicate the index of the contact you'd like to find:" << RESET << std::endl;
		std::cout << BLUE << std::right << std::setw(10) << "INDEX" << "|"
			<< std::setw(10) << "FIRST NAME" << "|"
			<< std::setw(10) << "LAST NAME" << "|"
			<< std::setw(10) << "NICKNAME" << RESET << std::endl;
		for (int i = 0; i < _ncontacts; i++)
		{
			std::cout << BLUE << std::right << std::setw(10) << _contact[i].getIndex() << "|"
				<< std::setw(10) << truncate(_contact[i].getFN()) << "|"
				<< std::setw(10) << truncate(_contact[i].getLN()) << "|"
				<< std::setw(10) << truncate(_contact[i].getNN()) << RESET << std::endl;
		}
		std::getline(std::cin, input);
		if (isValid(input))
		{
			int	index = std::atoi(input.c_str());
			std::cout << GREEN << "First name: " << _contact[index].getFN() << std::endl;
			std::cout << "Last name: " << _contact[index].getLN() << std::endl;
			std::cout << "Nickname: " << _contact[index].getNN() << std::endl;
			std::cout << "Phone number: " << _contact[index].getPN() << std::endl;
			std::cout << "Darkest secret: " << _contact[index].getDS() << RESET << std::endl;
		}
		else
			std::cout << RED << "Error! The input is not a valid index!" << RESET << std::endl;
		WelcomeMessage();
	}
}
