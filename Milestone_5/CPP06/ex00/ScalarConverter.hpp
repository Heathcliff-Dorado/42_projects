#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>
// # include <exception>
# include <limits>
# include <iomanip>
# include <cerrno>
# include <cmath>
# include <iostream>
# include <cstring>
# include <cstdlib>
# include "limits.h"

class ScalarConverter
{
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& copy );
	ScalarConverter&	operator=( const ScalarConverter& copy );
	~ScalarConverter();
public:
	static void	converter(std::string literal);
};

enum	literals{ CHAR, INT, FLOAT, DOUBLE, SPECIAL, OTHER } ;



#endif
