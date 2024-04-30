#include "Zombie.hpp"

int	main(void) {
	Zombie*	horde;

	horde = zombieHorde(8, "Paul");
	for (int i = 0; i < 8; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
