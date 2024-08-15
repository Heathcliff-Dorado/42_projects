#ifndef EASYFIND_T
# define EASYFIND_T

# include "easyfind.hpp"

template <typename T>
typename T::const_iterator	easyfind(T& haystack, int needle) {
	typename T::const_iterator	iter = std::find(haystack.begin(), haystack.end(), needle);

	if (iter != haystack.end())
		return (iter);
	throw std::out_of_range("No match found!");
}

#endif
