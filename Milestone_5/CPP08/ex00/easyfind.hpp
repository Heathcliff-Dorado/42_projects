#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <list>
# include <vector>

template <typename T>
typename T::const_iterator	easyfind(T& haystack, int needle);

# include "easyfind.tpp"

#endif
