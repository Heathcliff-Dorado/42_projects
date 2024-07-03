#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main( void ) {
	std::srand(std::time(0));
	Base* p = generate();
	identify(p);
	p = generate();
	identify(p);
	p = generate();
	identify(p);
	p = generate();
	identify(p);
	p = generate();
	identify(p);
	p = generate();
	identify(p);
	p = generate();
	identify(p);
}
