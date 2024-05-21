#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( const DiamondTrap& copy );
		DiamondTrap& operator=( const DiamondTrap& copy );
		~DiamondTrap();
		DiamondTrap( std::string name );

		void	guardGate( void );
		void	attack( const std::string& target );
};

#endif
