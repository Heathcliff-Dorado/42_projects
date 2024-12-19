#include "PmergeMe.hpp"
#include "PmergeList.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe vecSequence(argc, argv);
		vecSequence.mergeInsertSort();

		PmergeList listSequence(argc, argv);
		listSequence.mergeInsertSort();

		std::cout << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
		std::cout << "After: ";
		vecSequence.print();
		listSequence.print();
		vecSequence.getTime();
		listSequence.getTime();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
