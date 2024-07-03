#include "Serializer.hpp"

int	main( void ) {
	Data	data(5, "string");
	std::cout << "The data struct contains an int " << data.integer << " and a string " << data.string << std::endl;
	std::cout << "Calling the serializer and storing in a tmp variable" << std::endl;
	uintptr_t tmp = Serializer::serialize(&data);
	std::cout << "uintptr_t has value " << tmp << std::endl;
	std::cout << "Calling the serializer and storing in a different Data" << std::endl;
	Data *tmp2 = Serializer::deserialize(tmp);
	if (tmp2 == &data)
		std::cout << "They match!" << std::endl;
	else
		std::cout << "No match!" << std::endl;
	std::cout << "The second data struct contains an int " << tmp2->integer << " and a string " << tmp2->string << std::endl;
}
