#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap(), _name("Chrystal") {
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
	this->FragTrap::setHitPoints(100);
	this->ScavTrap::setEnergyPoints(100);
	this->FragTrap::setAttackDamage(30);
	this->ScavTrap::setName(_name + "_clap_name");
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy) : ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& copy) {
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	if (this != &copy)
		( void ) copy;

	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->_name << " (DiamondTrap): Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) : ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap: String constructor called" << std::endl;
	this->FragTrap::setHitPoints(100);
	this->ScavTrap::setEnergyPoints(100);
	this->FragTrap::setAttackDamage(30);
}
