#include "Span.hpp"

Span::Span( void ) : _capacity(0), _numbers() {
}

Span::Span( const Span& copy) : _capacity(copy._capacity), _numbers(copy._numbers) {
	*this = copy;
}

Span&	Span::operator=( const Span& copy) {
	if (this != &copy)
	{
		_capacity = copy._capacity;
		_numbers = copy._numbers;
	}

	return (*this);
}

Span::~Span() {
}

Span::Span( const unsigned int capacity ) : _capacity(capacity), _numbers() {
}

void	Span::addNumber( int number ) {
	std::pair<std::set<int>::iterator, bool> insert;
	if (_numbers.size() < _capacity)
		insert = _numbers.insert(number);
	if (insert.second == false)
		throw std::out_of_range("Couldn't insert the number, is it repeated?!");
	else if (_numbers.size() > _capacity)
		throw std::out_of_range("Can't add so many numbers!");
}

size_t	Span::longestSpan( void ) {
	size_t	span = *(--_numbers.end()) - *_numbers.begin();
	return (span);
}

size_t	Span::shortestSpan( void ) {
	size_t	distance = *(++_numbers.begin()) - *_numbers.begin();
	std::set<int>::const_iterator	current = _numbers.begin();
	std::set<int>::const_iterator	next = ++_numbers.begin();
	size_t	currentDistance;
	for (; next != _numbers.end(); next++, current++ )
	{
		currentDistance = *next - *current;
		if (currentDistance < distance)
			distance = currentDistance;
	}
	return distance;
}
