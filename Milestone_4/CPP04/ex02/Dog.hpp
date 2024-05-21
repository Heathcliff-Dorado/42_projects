#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
private:
	Brain*	_brain;
public:
	Dog( void );
	Dog( const Dog& copy);
	Dog& operator=( const Dog& copy);
	virtual ~Dog();
	virtual void		makeSound( void ) const;
	virtual void	setIdea( std::string idea, int index);
	virtual void	printIdea( int index);
};


#endif
