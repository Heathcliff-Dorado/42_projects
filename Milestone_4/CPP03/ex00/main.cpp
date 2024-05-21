#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap bob("Bob");

	std::cout << std::endl << "Name: " << bob.getName() << std::endl
			<< "HitPoints: " << bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << bob.getAttackDamage() << std::endl;

	std::cout << std::endl;
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");

	std::cout << std::endl << "Name: " << bob.getName() << std::endl
			<< "HitPoints: " << bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << bob.getAttackDamage() << std::endl;

	std::cout << std::endl;
	bob.takeDamage(5);
	bob.beRepaired(2);

	std::cout << std::endl << "Name: " << bob.getName() << std::endl
			<< "HitPoints: " << bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << bob.getAttackDamage() << std::endl;

	std::cout << std::endl;
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");
	bob.attack("my procrastination");

	std::cout << std::endl << "Name: " << bob.getName() << std::endl
			<< "HitPoints: " << bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << bob.getAttackDamage() << std::endl;

	std::cout << std::endl;
	bob.attack("my procrastination");
	bob.beRepaired(2);

	std::cout << std::endl;
	bob.takeDamage(6);

	std::cout << std::endl << "Name: " << bob.getName() << std::endl
			<< "HitPoints: " << bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << bob.getAttackDamage() << std::endl;

	std::cout << std::endl;
	bob.takeDamage(1);

	std::cout << std::endl << "Name: " << bob.getName() << std::endl
			<< "HitPoints: " << bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << bob.getAttackDamage() << std::endl;

	std::cout << std::endl;
	bob.attack("my procrastination");
	bob.beRepaired(2);
	std::cout << std::endl;
}
