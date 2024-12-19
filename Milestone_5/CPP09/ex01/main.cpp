#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}

	RPN rpnCalculator(argv[1]);
	rpnCalculator.calculateExpression();

	return 0;
}
