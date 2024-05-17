#include "Cat.hpp"
#include "Dog.hpp"

int	main( void ) {
	{
		Animal* farm[4];

		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 1)
				farm[i] = new Dog();
			else
				farm[i] = new Cat();
		}

		for (int i = 0; i < 4; i++)
			delete farm[i];
	}
}
