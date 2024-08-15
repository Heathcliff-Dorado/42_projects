#include "easyfind.hpp"

int main ( void )
{
	try
	{
		std::list<int>  lst;
		lst.push_back(1);
		lst.push_back(4);
		lst.push_back(6);
		std::cout << "List: " << *easyfind(lst, 6) << std::endl;
		std::cout << "List: " << *easyfind(lst, 3) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::vector<int> vec;
		vec.push_back(-1);
		vec.push_back(6);
		vec.push_back(3);
		vec.push_back(-1);
		std::cout << "Vector: " << *easyfind(vec, -1) << " followed by " << *(easyfind(vec, -1) + 1) << std::endl;
		std::cout << "Vector: " << *easyfind(vec, 0) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
