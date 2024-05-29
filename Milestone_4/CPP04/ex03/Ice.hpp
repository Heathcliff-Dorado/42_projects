#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice: public AMateria
{
private:
	/* data */
public:
	Ice( void );
	Ice( const Ice& copy );
	Ice& operator=(const Ice& copy );
	virtual ~Ice ( void );
	Ice(std::string const & type);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif
