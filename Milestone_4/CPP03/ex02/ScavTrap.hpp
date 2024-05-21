#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const ScavTrap& copy );
		ScavTrap& operator=( const ScavTrap& copy );
		~ScavTrap();
		ScavTrap( std::string name );

		void	guardGate( void );
		void	attack( const std::string& target );
};

#endif
