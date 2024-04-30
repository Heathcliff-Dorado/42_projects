#include "Zombie.hpp"

int	main(void) {
	Zombie*	stack;

	stack = newZombie("Foo");
	stack->announce();
	delete stack;
	randomChump("Boo");
	return (0);
}
