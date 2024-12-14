#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <string>
# include <stdexcept>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <fstream>

class Base
{
	public:
		virtual ~Base();
};

Base*	generate( void );
void	identify(Base* p);
void	identify(Base& p);

#endif
