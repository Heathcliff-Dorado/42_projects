#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat( void );
	Cat( const Cat& copy);
	Cat& operator=( const Cat& copy);
	virtual ~Cat();
	virtual void		makeSound( void ) const;
};


#endif
