#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class Phonebook {

private:

	Contact	_contacts[8];
	int		_count;

public:

	int	index;
	bool exit = false;
	Phonebook(void);
	~Phonebook(void);

	void	WelcomeMessage(void);
	void	AddContact(void);
	void	SearchContact(void);
};

#endif
