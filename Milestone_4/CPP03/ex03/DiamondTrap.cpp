#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap::ClapTrap("Chrystal_clap_name"), FragTrap(), ScavTrap(), _name("Chrystal") {
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy) : FragTrap::ClapTrap(copy._name + "_clap_name"), FragTrap(copy), ScavTrap(copy) {
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

DiamondTrap::DiamondTrap( std::string name) : FragTrap::ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	std::cout << "DiamondTrap: String constructor called" << std::endl;
	setAttackDamage(30);
}

void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "My name is " << _name << " but a part of me is also called " << ClapTrap::_name <<std::endl;
}
