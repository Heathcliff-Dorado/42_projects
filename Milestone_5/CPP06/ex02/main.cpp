#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main( void ) {
	std::srand(time(0));
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	p = generate();
	identify(p);
	identify(*p);
	delete p;
	p = generate();
	identify(p);
	identify(*p);
	delete p;
	p = generate();
	identify(p);
	identify(*p);
	delete p;
	p = generate();
	identify(p);
	identify(*p);
	delete p;
	p = generate();
	identify(p);
	identify(*p);
	delete p;
	p = generate();
	identify(p);
	identify(*p);
	delete p;
}
