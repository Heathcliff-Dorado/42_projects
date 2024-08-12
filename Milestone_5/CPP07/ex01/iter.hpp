#ifndef ITER_H
# define ITER_H

# include <iostream>


template <typename T, typename U>
void	iter(T& array, std::size_t length, U function)
{
	for (std::size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
