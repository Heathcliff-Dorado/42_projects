#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure: public AMateria
{
private:
	/* data */
public:
	Cure( void );
	Cure( const Cure& copy );
	Cure& operator=(const Cure& copy );
	virtual ~Cure ( void );
	Cure(std::string const & type);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif
