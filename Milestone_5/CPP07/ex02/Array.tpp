#ifndef ARRAY_T
# define ARRAY_T

# include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _elements(NULL), _n(0) {};

template <typename T>
Array<T>::Array( const Array& copy )
{
	*this = copy;
};

template <typename T>
Array<T>& Array<T>::operator=( const Array& copy )
{
	if (this != &copy)
	{
		_n = copy._n;
		_elements = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			_elements[i] = copy._elements[i];
	}
	return (*this);
};

template <typename T>
Array<T>::~Array( void )
{
	delete[] _elements;
};

template <typename T>
Array<T>::Array( unsigned int n ) : _n(n)
{
		_elements = new T[_n]();
};

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _n)
		throw std::out_of_range("Error: Index out of scope!");
	return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _n)
		throw std::out_of_range("Index out of scope!");
	return _elements[index];
}

template <typename T>
unsigned int	Array<T>::size( void ) const
{
	return (_n);
}

#endif
