#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <string>

const std::string RED = "\033[1;31m";
const std::string MAGENTA = "\033[1;35m";
const std::string CYAN = "\033[1;36m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string RESET = "\033[0m";

class Contact
{

	private:
		int	_index;
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_Secret;
	public:
		Contact( void );
		~Contact();
		void	setIndex( int index);
		void	setFN( std::string info);
		void	setLN( std::string info);
		void	setNN( std::string info);
		void	setPN( std::string info);
		void	setDS( std::string info);
		int		getIndex( void );
		std::string	getFN( void );
		std::string	getLN( void );
		std::string	getNN( void );
		std::string	getPN( void );
		std::string	getDS( void );
};

#endif
