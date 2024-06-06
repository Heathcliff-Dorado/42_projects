#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _index(0) {
	//std::cout << "Materia source created" << std::endl;
	for (int i = 0; i < 4; i++)
		_stock[i] = 0;
}

MateriaSource::MateriaSource( const MateriaSource& copy) {
	//std::cout << "Materia source copy created" << std::endl;
	*this = copy;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (copy._stock[i])
				_stock[i] = copy._stock[i]->clone();
		}
	}

	return (*this);
}

MateriaSource::~MateriaSource() {
	//std::cout << "Materia source deleted" << std::endl;
	for (int i = 0; i < _index; i++)
	{
		if (_stock[i])
			delete _stock[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (_index < 4)
	{
		_stock[_index] = m;
		_index++;
	}
	else
	{
		std::cout << "This Materia source is full!" << std::endl;
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++)
	{
		if (_stock[i] && _stock[i]->getType() == type)
			return (_stock[i]->clone());
	}
	return (0);
}
