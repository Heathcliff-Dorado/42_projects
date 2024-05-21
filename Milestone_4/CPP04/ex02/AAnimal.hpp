#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class AAnimal
{
private:
	/* data */
protected:
	std::string	type;
public:
	AAnimal( void );
	AAnimal( const AAnimal& copy);
	AAnimal& operator=( const AAnimal& copy);
	virtual ~AAnimal();
	virtual void		makeSound( void ) const = 0;
	void		setType( std::string type);
	const std::string	getType( void ) const;
	virtual void	setIdea( std::string idea, int index);
	virtual void	printIdea( int index);
};

#endif
