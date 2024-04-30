#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {

	private:

		std::string _name;

	public:

		Zombie ( void );
		Zombie (std::string Zname);
		~Zombie ( void );
		void	announce ( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
