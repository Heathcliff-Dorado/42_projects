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
# include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
