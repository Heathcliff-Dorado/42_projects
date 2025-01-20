// #include "Array.hpp"

// int	main(void) {
// 	try
// 	{
// 		Array<int>	first;

// 		std::cout << "Created an array with " << first.size() << " elements" << std::endl << std::endl;

// 		Array<std::string>	second(4);

// 		std::cout << "Created an array with " << second.size() << " elements" << std::endl;
// 		for (unsigned int i = 0; i < second.size(); i++)
// 			std::cout << "Element " << i << " contains " << second[i] << std::endl;
// 		std::cout << "Assigning strings to the array" << std::endl;
// 		second[0] = "Hello";
// 		second[1] = "How are you";
// 		second[2] = "I like you!";
// 		second[3] = "Good bye!";
// 		for (unsigned int i = 0; i < second.size(); i++)
// 			std::cout << "Element " << i << " contains " << second[i] << std::endl;
// 		std::cout << "Testing out of bounds" << std::endl;
// 		second[4];
// 	}
// 	catch(const std::exception& e)
//     {
//         std::cerr << "Error: " << e.what() << '\n';
//     }
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 20

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	std::cout << "Confirming that array is initialized: " << numbers[0] << std::endl;
	std::cout << "Testing function size: " << numbers.size() << " (should be " << MAX_VAL << ")" << std::endl;

	srand(time(NULL));
	std::cout << "Populating array and mirror (pointer of int)" <<std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout << "Array position " << i << " and value " << value << std::endl;
	}
	std::cout << "Confirming both array and int * have the same information (no error should be thrown)" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "Error: Didn't save the same value!!" << std::endl;
			delete [] mirror;
			return 1;
		}
	}
	std::cout << "All good!" <<std::endl;
	//SCOPE
	std::cout << std::endl << "Duplicating arrays" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "First position of tmp is " << tmp[0] << " and of test is " << test[0] << " and original is " << numbers[0] << std::endl << std::endl;
	}


	try
	{
		std::cout << "Trying a big index! (should throw an error)" <<std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "Changing the values of the array" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "Previous value: " << numbers[i];
		numbers[i] = rand();
		std::cout << " new value: " << numbers[i] << std::endl;
	}
	delete [] mirror;//
	return 0;
}
