#include "iter.hpp"

template <typename T>
void	printElement(T& element)
{
	std::cout << element << " ";
}

int	main(void)
{
	int	iArray[] = {0,1,2,3};
	std::string	stringArray[] = {"Hello", "beautiful", "world", "!"};

	iter(iArray, (std::size_t) 4, printElement<int>);
	std::cout << std::endl << std::endl;
	iter(stringArray, (std::size_t) 4, printElement<std::string>);
	std::cout << std::endl << std::endl;
}
