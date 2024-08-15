#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <set>
# include <vector>

class Span
{
private:
	Span( void );
	unsigned int	_capacity;
	std::set<int>	_numbers;
public:
	Span( const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	Span( const unsigned int capacity );

	void		addNumber( int number );
	size_t		shortestSpan( void );
	size_t		longestSpan( void );

	template <typename RIt>
	void	massAddNumber( RIt first, RIt last );
};

template <typename RIt>
void	Span::massAddNumber( RIt first, RIt last ) {
	size_t space = (size_t)_capacity - _numbers.size();
	size_t needed = std::distance(first, last);
	if ( needed < space)
		_numbers.insert(first, last);
	else
		throw std::out_of_range("Can't add so many numbers!");
}

#endif
