#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		int	_index;
		AMateria*	_inventory[4];
		int	_uindex;
		AMateria*	_uinventory[1024];
	public:
		Character( void );
		Character( const Character& copy );
		Character& operator=(const Character& copy );
		virtual ~Character();
		Character( std::string name);
		virtual std::string const& getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
