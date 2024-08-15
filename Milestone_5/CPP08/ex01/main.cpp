#include "Span.hpp"
#include <list>

int main ( void )
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::srand(time(0));
		Span sp = Span(100000);
		std::vector<int>	vector;
		for (int i = 0; i < 80000; i++)
		{
			vector.push_back(rand());
		}
		sp.massAddNumber(vector.begin(), vector.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
