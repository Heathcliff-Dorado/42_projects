#include <iostream>
#include <cstring>

int	main (int ac, char **av)
{
	int i;
	int	j;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < ac)
		{
			j = -1;
			while (++j < (int) strlen(av[i]))
				std::cout << (char) toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
