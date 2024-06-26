#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( const WrongCat& copy);
	WrongCat& operator=( const WrongCat& copy);
	virtual ~WrongCat();
	void		makeSound( void ) const;
};


#endif
