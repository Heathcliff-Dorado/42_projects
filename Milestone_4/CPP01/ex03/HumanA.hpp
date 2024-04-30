#ifndef HUMAN_A_H
# define HUMAN_A_H
# include "Weapon.hpp"

class HumanA
{

	private:
		std::string _name;
		Weapon&		_weapon;
	public:
		//HumanA( void );
		HumanA(std::string name, Weapon& weapon);
		~HumanA( void );
		void	attack( void );
		void	setWeapon(Weapon weapon2);
};

#endif
