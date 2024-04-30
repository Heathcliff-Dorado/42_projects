#ifndef HUMAN_B_H
# define HUMAN_B_H
# include "Weapon.hpp"

class HumanB
{

	private:
		std::string _name;
		Weapon*		_weapon;
	public:
		//HumanB( void );
		HumanB(std::string name);
		~HumanB( void );
		void	attack( void );
		void	setWeapon(Weapon& weapon2);
};

#endif
