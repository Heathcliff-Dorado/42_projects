#include "Span.hpp"
#include <list>

int main ( void )
{
	try
	{
		std::cout << "Trying with a Span of 5" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Trying with a Span of 100000, using an iterator" << std::endl;
		std::srand(time(0));
		Span sp = Span(100000);
		std::vector<int>	vector;
		for (int i = 0; i < 80000; i++)
		{
			vector.push_back(rand());
		}
		sp.massAddNumber(vector.begin(), vector.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying to add a number twice" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(6);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl<< "Trying to add more numbers than what fits" << std::endl;
		std::srand(time(0));
		Span sp = Span(100000);
		std::vector<int>	vector;
		for (int i = 0; i < 100000; i++)
		{
			vector.push_back(rand());
		}
		sp.massAddNumber(vector.begin(), vector.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
