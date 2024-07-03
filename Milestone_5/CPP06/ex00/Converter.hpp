#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>
# include <exception>
# include <limits>
# include <iomanip>

class Converter
{
private:
	Converter( void );
	Converter( const Converter& copy );
	Converter&	operator=( const Converter& copy );
	~Converter();
public:
	static void	converter(std::string literal);
};

enum	literals{ CHAR, INT, FLOAT, DOUBLE, SPECIAL, OTHER } ;



#endif
