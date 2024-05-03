#include "Harl.hpp"

int	main(int argc, char **argv) {

	if (argc != 2)
		std::cout << "Please let me know what I should complain about (DEBUG, INFO, WARNING or ERROR)" <<std::endl;
	Harl harl;
	int	i = 0;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (argv[1] == levels[i])
			break ;
		i++;
	}
	switch (i)
	{
	case 0:
		harl.complain(levels[i]);
		break;
	case 1:
		harl.complain(levels[i]);
		break;
	case 2:
		harl.complain(levels[i]);
		break;
	case 3:
		harl.complain(levels[i]);
		break;
	default:
		harl.complain(argv[1]);
		break;
	}
	return 0;
}
