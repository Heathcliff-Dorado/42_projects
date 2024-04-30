#include "Phonebook.hpp"

int	main( void ) {
	Phonebook	book;
	std::string	message;

	book.WelcomeMessage();
	std::getline(std::cin, message);
	while (message.compare("EXIT") != 0)
	{
		if (message.compare("ADD") == 0)
			book.AddContact();
		else if (message.compare("SEARCH") == 0)
			book.SearchContact();
		else
			book.WelcomeMessage();
		std::getline(std::cin, message);
	}
}
