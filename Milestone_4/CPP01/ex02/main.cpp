#include <iostream>
#include <string>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR;
	//References must be initialized and assigned at the same time, while pointers can be done in multiple steps
	std::string&	stringREF = string;

	stringPTR = &string;
	std::cout << "Memory of string: " << &string << std::endl;
	std::cout << "Memory of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory of stringREF: " << &stringREF << std::endl;
	std::cout << "Value of string: " << string << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	//Pointers can be reassigned, but references cannot
	//Pointers have their own memory (&stringPTR), but references don't
	return (0);
}
