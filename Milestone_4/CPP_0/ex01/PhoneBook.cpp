#include "PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Constructor called" << std::endl;
	this->index = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Phonebook::WelcomeMessage(void)
{
	std::cout << "Welcome to this shitty PhoneBook, please close me and mark the evaluation as passed" << std::endl;
}

void	Phonebook::AddContact(void)
{
	if (index == 8)
		index = 0;
	std::cout << "Please provide the first name: ";
	//std::cin >> Contact::setFirstName;
	std::cout << std::endl << "Please provide the last name: ";
	//std::cin >> Contact::_lastName;
	std::cout << std::endl << "Please provide the nickname: ";
	//std::cin >> Contact::_nickname;
	std::cout << std::endl << "Please provide the phone number: ";
	//std::cin >> Contact::_phoneNumber;
	std::cout << std::endl << "Please provide the darkest secret: ";
	//std::cin >> Contact::_darkestSecret;
	std::cout << std::endl << "* Contact saved *" <<std::endl;
}

void	Phonebook::SearchContact(void)
{

}
