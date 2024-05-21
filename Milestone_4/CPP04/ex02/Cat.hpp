#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
private:
	Brain*	_brain;
public:
	Cat( void );
	Cat( const Cat& copy);
	Cat& operator=( const Cat& copy);
	virtual ~Cat();
	virtual void		makeSound( void ) const;
	virtual void	setIdea( std::string idea, int index);
	virtual void	printIdea( int index);
};


#endif
