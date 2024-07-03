#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base() {

}

Base*	generate( void ) {

	int random = std::rand();
	if (random % 3 == 1)
		return new A;
	else if (random % 3 == 2)
		return new B;
	else
		return new C;
}

void	identify(Base* p) {

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Neither A, B, or C" << std::endl;
}

void	identify(Base& p) {

	try
	{
		A&	a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void) a;
	}
	catch (const std::bad_cast&)
	{
		try
		{
			B&	b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void) b;
		}
		catch (const std::bad_cast &)
		{
			try
			{
				C&	c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void) c;
			}
			catch (const std::bad_cast &)
			{
				std::cout << "Neither A, B, or C" << std::endl;
			}
		}
	}
}
