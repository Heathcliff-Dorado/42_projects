#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain*	_brain;
public:
	Dog( void );
	Dog( const Dog& copy);
	Dog& operator=( const Dog& copy);
	virtual ~Dog();
	virtual void		makeSound( void ) const;
};


#endif
