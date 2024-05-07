#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap bob("Bob");

	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.takeDamage(5);
	bob.beRepaired(2);
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.beRepaired(2);
	bob.takeDamage(6);
	bob.takeDamage(1);
	bob.attack("my procrastination");
	bob.beRepaired(2);
}
