#ifndef BRAIN_H
# define BRAIN_H

# include "AAnimal.hpp"

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain( void );
	Brain (const Brain& copy);
	Brain& operator=(const Brain& copy);
	~Brain();

	void	addIdea(std::string idea, int index);
	std::string	getIdea( int index );
};

#endif
