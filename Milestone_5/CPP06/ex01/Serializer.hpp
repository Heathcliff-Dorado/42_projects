#ifndef SERIALIZER_H
# define SERIALIZER_H

# include "Data.hpp"

class Serializer
{
private:
	Serializer( void );
	Serializer( const Serializer& copy );
	Serializer&	operator=( const Serializer& copy );
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
