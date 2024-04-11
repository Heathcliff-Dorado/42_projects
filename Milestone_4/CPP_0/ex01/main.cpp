#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	Phonebook	mybook;
	std::string	input;

	mybook.WelcomeMessage();
	std::cin >> input;
	while (input.compare("EXIT") != 0)
	{
		if(input.compare("ADD") == 0)
			mybook.AddContact();
		if(input.compare("SEARCH") == 0)
			mybook.SearchContact();
		mybook.WelcomeMessage();
		std::cin >> input;
	}
}
