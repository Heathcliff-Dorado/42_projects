#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream btcDB("data.csv");
	if (!btcDB)
	{
		std::cerr << "Error: could not open data base file." << std::endl;
		return 1;
	}

	BitcoinExchange btcExchange(btcDB);
	btcExchange.processInputFile(inputFile);
	inputFile.close();

	return 0;
}
