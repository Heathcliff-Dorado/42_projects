#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Clappy"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap: Default constructor called with the name " << _name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy) {
	std::cout << "ClapTrap: Copy constructor called with the name " << _name << std::endl;
	*this = copy;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& copy) {
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		setName(copy._name);
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}

	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << _name << " (ClapTrap): Destructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap: String constructor called with the name " << _name << std::endl;
}

void	ClapTrap::setName( std::string name ) {
	_name = name;
}

void	ClapTrap::attack( const std::string& target ) {
	if (this->_hitPoints <= 1)
		std::cout << _name << " has lost all their health points and can't attack anymore!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << _name << " has no energy left and can't attack anymore!" << std::endl;
	else
	{
		std::cout << _name << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	std::cout << _name << " takes " << amount << " points of damage!" <<std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		std::cout << _name << " has lost all their health points!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_hitPoints <= 0)
		std::cout << _name << " has lost all their health points and can't repair themselves!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << _name << " has no energy left and can't repair themselves!" << std::endl;
	else
	{
		std::cout << _name << " recovers " << amount << " health points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}

void	ClapTrap::setHitPoints( int points ) {
	_hitPoints = points;
}

void	ClapTrap::setEnergyPoints( int points ) {
	_energyPoints = points;
}

void	ClapTrap::setAttackDamage( int points ) {
	_attackDamage = points;
}

std::string	ClapTrap::getName( void )
{
	return (this->_name);
}
int	ClapTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}
int	ClapTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}
int	ClapTrap::getAttackDamage( void )
{
	return (this->_attackDamage);
}
