#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_stock[4];
		int			_index;
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& copy );
		MateriaSource& operator=(const MateriaSource& copy );
		~MateriaSource();

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
