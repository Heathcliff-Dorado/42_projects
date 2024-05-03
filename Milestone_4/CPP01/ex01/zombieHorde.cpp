#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	Zombie* horde;

	//Filling the horde with Zombies automatically constructs them,
	horde =	new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		// If we announce it at this point, the zombies will receive the default name BackgroundZ
		//horde[i].announce();
		horde[i].setName(name);
		// then the name changes to their given name:
		//horde[i].announce();
	}
	return horde;
}
