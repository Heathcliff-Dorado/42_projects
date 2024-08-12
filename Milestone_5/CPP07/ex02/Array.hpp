#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <cstdlib>
# include <ctime>

template <typename T>
class Array
{
	public:
		Array( void );
		Array( const Array& copy );
		Array&	operator=( const Array& copy );
		~Array();
		Array( unsigned int n );
	private:
		T*				_elements;
		unsigned int	_n;

};

#include "Array.tpp"

#endif
