#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource( void );
		IMateriaSource( const IMateriaSource& copy );
		IMateriaSource& operator=(const IMateriaSource& copy );
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
