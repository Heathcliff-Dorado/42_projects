#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->setName("Scavy");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap( const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& copy) {
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if (this != &copy)
	// 	ClapTrap::operator=(copy);
		( void ) copy;

	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap: String constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

void	ScavTrap::guardGate( void ) {
	std::cout << _name << " is guarding something now!" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (this->_hitPoints <= 1)
		std::cout << getName() << " decided to nap forever and can't attack anymore!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << getName() << " is too hungry and can't attack anymore!" << std::endl;
	else
	{
		std::cout << getName() << " devastates " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}
