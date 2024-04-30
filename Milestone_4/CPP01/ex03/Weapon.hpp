#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>
# include <string>

class Weapon {

	public:

		Weapon( void );
		Weapon( std::string WeaponType );
		~Weapon( void );
		const std::string&	getType( void );
		void				setType( std::string type);

	private:

		std::string	_type;

};


#endif
