#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound(); //will output the cat sound!
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* meta = new WrongCat();
		const WrongCat* i = new WrongCat();
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();
		delete meta;
		delete i;
	}
}
