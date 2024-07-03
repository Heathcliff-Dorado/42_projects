#include "Converter.hpp"

int	main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cout << "Usage: <program name> <argument>" << std::endl;
		return (1);
	}
	Converter::converter(argv[1]);
	return (0);
}
