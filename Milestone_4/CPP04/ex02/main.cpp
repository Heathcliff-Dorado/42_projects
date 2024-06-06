#include "Cat.hpp"
#include "Dog.hpp"

int	main( void ) {
	{
		//AAnimal test;
		AAnimal* farm[4];
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 1)
				farm[i] = new Dog();
			else
				farm[i] = new Cat();
		}
		farm[0]->makeSound();
		farm[0]->printIdea(3);
		farm[0]->setIdea("I never have to clean my shit, so who domesticated whom?", 3);
		farm[0]->printIdea(3);
		for (int i = 0; i < 4; i++)
			delete farm[i];
	}
}
