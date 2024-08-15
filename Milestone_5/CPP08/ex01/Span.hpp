#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <list>
# include <vector>

class Span
{
private:
	Span( void );
	unsigned int	_capacity;
	std::list<int>	_numbers;
public:
	Span( const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	Span( const unsigned int capacity );

	void	addNumber( int number );
	int		shortestSpan( void );
	int		longestSpan( void );
	void	massAddNumber( );
};

#endif
