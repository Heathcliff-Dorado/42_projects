#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {
	ClapTrap	Boba("Boba");

	std::cout << std::endl;
	Boba.attack("my procrastination");
	Boba.takeDamage(5);
	Boba.beRepaired(3);
	std::cout << std::endl<< "Name: " << Boba.getName() << std::endl
			<< "HitPoints: " << Boba.getHitPoints() << std::endl
			<< "EnergyPoints: " << Boba.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Boba.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ScavTrap	Bob("Bob");

	std::cout << std::endl;
	Bob.attack("my procrastination");
	Bob.takeDamage(5);
	Bob.guardGate();
	std::cout << std::endl << "Name: " << Bob.getName() << std::endl
			<< "HitPoints: " << Bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bob.getAttackDamage() << std::endl;
	std::cout << std::endl;

	FragTrap	Bubby("Bubby");

	std::cout << std::endl;
	Bubby.attack("my procrastination");
	Bubby.takeDamage(5);
	Bubby.highFivesGuys();
	std::cout << std::endl<< "Name: " << Bubby.getName() << std::endl
			<< "HitPoints: " << Bubby.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bubby.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bubby.getAttackDamage() << std::endl << std::endl;
	std::cout << std::endl;

	DiamondTrap	Boss("Boss");

	std::cout << std::endl;
	Boss.attack("my procrastination");
	Boss.takeDamage(5);
	std::cout << std::endl<< "Name: " << Boss.getName() << std::endl
			<< "HitPoints: " << Boss.getHitPoints() << std::endl
			<< "EnergyPoints: " << Boss.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Boss.getAttackDamage() << std::endl << std::endl;
	std::cout << std::endl;
}
