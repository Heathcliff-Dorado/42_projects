#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap: Default constructor called" << std::endl;
	this->setName("Scavy");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap( const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator=( const FragTrap& copy) {
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &copy)
		( void ) copy;

	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << _name << " (FragTrap): Destructor called" << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap(name) {
	std::cout << "FragTrap: String constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}


void	FragTrap::highFivesGuys( void ) {
	std::cout << _name << ": High five bro!🙏" <<std::endl;
}
void	FragTrap::attack( const std::string& target ) {
	if (this->_hitPoints <= 1)
		std::cout << getName() << " is too cool to be alive and can't attack anymore!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << getName() << " is too cool to have energy and can't attack anymore!" << std::endl;
	else
	{
		std::cout << getName() << "'s coolness targets " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}
