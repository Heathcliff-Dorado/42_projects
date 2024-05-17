#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include "Animal.hpp"

class WrongAnimal
{
private:
	/* data */
protected:
	std::string	type;
public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& copy);
	WrongAnimal& operator=( const WrongAnimal& copy);
	virtual ~WrongAnimal();
	void		makeSound( void ) const;
	void		setType( std::string type);
	const std::string	getType( void ) const;
};

#endif
