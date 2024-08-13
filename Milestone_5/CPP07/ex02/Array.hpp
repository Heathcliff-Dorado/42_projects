#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
#include <cstdlib>
#include <ctime>
# include <exception>
# include <limits>
# include <iomanip>
#include <cerrno>
#include <cmath>
#include <climits>
# include <stdint.h>
# include <typeinfo>

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_n;
	public:
		Array( void );
		Array( const Array& copy );
		Array&	operator=( const Array& copy );
		~Array();
		Array( unsigned int n );

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int	size( void ) const;
};

#include "Array.tpp"

#endif
