#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const FragTrap& copy );
		FragTrap& operator=( const FragTrap& copy );
		~FragTrap();
		FragTrap( std::string name );

		void	highFivesGuys( void );
		void	attack( const std::string& target );
};

#endif
