#include "Character.hpp"

Character::Character( void ) : _name("Noname"), _index(0), _uindex(0)  {
	std::cout << "Character created" << std::endl;
}

Character::Character( const Character& copy) {
	std::cout << "Character copy created" << std::endl;
	*this = copy;
}

Character&	Character::operator=( const Character& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_index = copy._index;
		_uindex = copy._uindex;
		for (int i = 0; i < _index; i++)
			_inventory[i] = copy._inventory[i]->clone();
		for (int i = 0; i < _uindex; i++)
			_uinventory[i] = copy._uinventory[i]->clone();
	}

	return (*this);
}

Character::~Character() {
	std::cout << "Character deleted" << std::endl;
	for (int i = 0; i < _index; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < _uindex; i++)
	{
		if (_uinventory[i])
			delete _uinventory[i];
	}
}

Character::Character( std::string name ) :_name(name), _index(0), _uindex(0) {
	std::cout << "String character created" <<std::endl;
}

std::string const& Character::getName() const {
	return(_name);
}

void Character::equip(AMateria* m) {
	if (_index < 4)
	{
		std::cout << "Materia " << m->getType() << " equiped!" <<std::endl;
		_inventory[_index] = m;
		_index++;
	}
	else
	{
		std::cout << "Too many materias already equipped!" << std::endl;
		delete m;
	}
}

void Character::unequip(int idx) {
	if (idx < _index)
	{
		_uinventory[_uindex] = _inventory[idx];
		_uindex++;
		_inventory[idx] = 0;
	}
	else
		std::cout << "That command can't be done, since that materia doesn't exist" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < _index && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Nothing to use since that materia doesn't exist" << std::endl;
}
