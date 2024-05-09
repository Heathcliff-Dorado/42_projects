#include "ScavTrap.hpp"

int	main( void ) {
	// ClapTrap bob("Bob");

	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.takeDamage(5);
	// bob.beRepaired(2);
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.attack("my procrastination");
	// bob.beRepaired(2);
	// bob.takeDamage(6);
	// bob.takeDamage(1);
	// bob.attack("my procrastination");
	// bob.beRepaired(2);
	ScavTrap	Bob;

	Bob.attack("my procrastination");

	ScavTrap	Terry(Bob);

	Bob.takeDamage(5);

	ScavTrap	Bruno = Bob;

	Bob.takeDamage(5);

	ScavTrap	Helgo("Helgo");
	ClapTrap	Boba;

	Boba.attack("my procrastination");

	ClapTrap	Terrya(Boba);

	Boba.takeDamage(5);

	ClapTrap	Bruna = Boba;

	Boba.takeDamage(5);

	ClapTrap	Helga("Helga");

	std::cout << "Name: " << Bob.getName() << std::endl
			<< "HitPoints: " << Bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bob.getAttackDamage() << std::endl;

	std::cout << "Name: " << Terry.getName() << std::endl
			<< "HitPoints: " << Terry.getHitPoints() << std::endl
			<< "EnergyPoints: " << Terry.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Terry.getAttackDamage() << std::endl;

	std::cout << "Name: " << Bruno.getName() << std::endl
			<< "HitPoints: " << Bruno.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bruno.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bruno.getAttackDamage() << std::endl;

	std::cout << "Name: " << Helgo.getName() << std::endl
			<< "HitPoints: " << Helgo.getHitPoints() << std::endl
			<< "EnergyPoints: " << Helgo.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Helgo.getAttackDamage() << std::endl;

	std::cout << "Name: " << Boba.getName() << std::endl
			<< "HitPoints: " << Boba.getHitPoints() << std::endl
			<< "EnergyPoints: " << Boba.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Boba.getAttackDamage() << std::endl;

	std::cout << "Name: " << Terrya.getName() << std::endl
			<< "HitPoints: " << Terrya.getHitPoints() << std::endl
			<< "EnergyPoints: " << Terrya.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Terrya.getAttackDamage() << std::endl;

	std::cout << "Name: " << Bruna.getName() << std::endl
			<< "HitPoints: " << Bruna.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bruna.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bruna.getAttackDamage() << std::endl;

	std::cout << "Name: " << Helga.getName() << std::endl
			<< "HitPoints: " << Helga.getHitPoints() << std::endl
			<< "EnergyPoints: " << Helga.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Helga.getAttackDamage() << std::endl;

	Bob.guardGate();
}
