#ifndef DATA_H
# define DATA_H

# include <iostream>
# include <string>
# include <exception>
# include <limits>
# include <iomanip>
# include <stdint.h>

struct Data
{
	int			integer;
	std::string	string;
	Data(int i, const std::string &s) : integer(i), string(s) {};
};

#endif
