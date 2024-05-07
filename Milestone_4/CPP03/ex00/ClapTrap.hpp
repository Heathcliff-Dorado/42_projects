#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
public:
	ClapTrap( void );
	ClapTrap( const ClapTrap& copy );
	ClapTrap& operator=( const ClapTrap& copy );
	~ClapTrap();
	ClapTrap( std::string name );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	void	setName( std::string name );
	void	setHitPoints( int points );
	void	setEnergyPoints( int points );
	void	setAttackDamage( int points );

	std::string	getName( void );
	int			getHitPoints( void );
	int			getEnergyPoints( void );
	int			getAttackDamage( void );
};

#endif
