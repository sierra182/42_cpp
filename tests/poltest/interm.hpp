#include "base.hpp"
#include <cstdlib>
class Interm :public Base
{
	// using Base::funct;
	public:
		
		Interm() { std::cout << "Interm Constructor" << std::endl; }
		Interm(const Interm &) { std::cout << "Interm COPY Constructor" << std::endl; }
		~Interm() {std::cout << "Interm Destructor" << std::endl;}
	virtual void foo2()  {std::cout << "foo2 interm" << std::endl;}
		 void foo()  {std::cout << "!!!! foo interm" << std::endl;}
};