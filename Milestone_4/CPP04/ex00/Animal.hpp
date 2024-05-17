#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal
{
private:
	/* data */
protected:
	std::string	type;
public:
	Animal( void );
	Animal( const Animal& copy);
	Animal& operator=( const Animal& copy);
	virtual ~Animal();
	virtual void		makeSound( void ) const;
	void		setType( std::string type);
	const std::string	getType( void ) const;
};

#endif
