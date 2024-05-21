#include "ScavTrap.hpp"

int	main( void ) {
	ScavTrap	Bob;

	std::cout << std::endl;
	std::cout << "Name: " << Bob.getName() << std::endl
			<< "HitPoints: " << Bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bob.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Bob.attack("my procrastination");

	std::cout << std::endl;
	std::cout << "Name: " << Bob.getName() << std::endl
			<< "HitPoints: " << Bob.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bob.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bob.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ScavTrap	Terry(Bob);

	std::cout << std::endl;
	std::cout << "Name: " << Terry.getName() << std::endl
			<< "HitPoints: " << Terry.getHitPoints() << std::endl
			<< "EnergyPoints: " << Terry.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Terry.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Terry.takeDamage(5);

	std::cout << std::endl;
	std::cout << "Name: " << Terry.getName() << std::endl
			<< "HitPoints: " << Terry.getHitPoints() << std::endl
			<< "EnergyPoints: " << Terry.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Terry.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ScavTrap	Bruno = Terry;

	std::cout << std::endl;
	std::cout << "Name: " << Bruno.getName() << std::endl
			<< "HitPoints: " << Bruno.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bruno.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bruno.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Bruno.takeDamage(5);
	Bruno.guardGate();

	std::cout << std::endl;
	std::cout << "Name: " << Bruno.getName() << std::endl
			<< "HitPoints: " << Bruno.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bruno.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bruno.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ScavTrap	Helgo("Helgo");

	std::cout << std::endl;
	std::cout << "Name: " << Helgo.getName() << std::endl
			<< "HitPoints: " << Helgo.getHitPoints() << std::endl
			<< "EnergyPoints: " << Helgo.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Helgo.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ClapTrap	Boba;

	std::cout << std::endl;
	std::cout << "Name: " << Boba.getName() << std::endl
			<< "HitPoints: " << Boba.getHitPoints() << std::endl
			<< "EnergyPoints: " << Boba.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Boba.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Boba.attack("my procrastination");

	std::cout << std::endl;
	std::cout << "Name: " << Boba.getName() << std::endl
			<< "HitPoints: " << Boba.getHitPoints() << std::endl
			<< "EnergyPoints: " << Boba.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Boba.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ClapTrap	Terrya(Boba);

	std::cout << std::endl;
	std::cout << "Name: " << Terrya.getName() << std::endl
			<< "HitPoints: " << Terrya.getHitPoints() << std::endl
			<< "EnergyPoints: " << Terrya.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Terrya.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Terrya.takeDamage(5);

	std::cout << std::endl;
	std::cout << "Name: " << Terrya.getName() << std::endl
			<< "HitPoints: " << Terrya.getHitPoints() << std::endl
			<< "EnergyPoints: " << Terrya.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Terrya.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ClapTrap	Bruna = Terrya;

	std::cout << std::endl;
	std::cout << "Name: " << Bruna.getName() << std::endl
			<< "HitPoints: " << Bruna.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bruna.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bruna.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Bruna.takeDamage(5);

	std::cout << std::endl;
	std::cout << "Name: " << Bruna.getName() << std::endl
			<< "HitPoints: " << Bruna.getHitPoints() << std::endl
			<< "EnergyPoints: " << Bruna.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Bruna.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ClapTrap	Helga("Helga");

	std::cout << std::endl;
	std::cout << "Name: " << Helga.getName() << std::endl
			<< "HitPoints: " << Helga.getHitPoints() << std::endl
			<< "EnergyPoints: " << Helga.getEnergyPoints() << std::endl
			<< "AttackDamage: " << Helga.getAttackDamage() << std::endl;
	std::cout << std::endl;
}
