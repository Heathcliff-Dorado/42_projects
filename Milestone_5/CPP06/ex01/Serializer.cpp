#include "Serializer.hpp"

Serializer::Serializer( void ) {
	//std::cout << "Serializer created" << std::endl;
}

Serializer::Serializer( const Serializer& copy) {
	//std::cout << "Serializer copy created" << std::endl;
	*this = copy;
}

Serializer&	Serializer::operator=( const Serializer& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}

	return (*this);
}

Serializer::~Serializer() {
	//std::cout << "Converter deleted" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
