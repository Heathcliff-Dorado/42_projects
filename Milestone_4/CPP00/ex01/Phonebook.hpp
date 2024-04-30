#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>

class Phonebook {

	private:
		Contact	_contact[8];
		int		_ncontacts;
		int		_nextIndex;

	public:
		Phonebook( void );
		~Phonebook( void );
		std::string	truncate(std::string info);
		bool	isValid( std::string input );
		void	WelcomeMessage( void );
		void	AddContact( void );
		void	SearchContact( void );

};

#endif
