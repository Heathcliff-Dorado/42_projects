#ifndef TEMPLATE_H
# define TEMPLATE_H

# include <iostream>


template <typename T>
void	swap(T& a, T& b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
const	T&	min(T& a, T& b)
{
	if (a <= b)
		return (a);
	return (b);
}

template <typename T>
const	T&	max(T& a, T& b)
{
	if (a >= b)
		return (a);
	return (b);
}

#endif
