#include "interm.hpp"

class Final : public Interm
{
	public:
		Final() { std::cout << "Final Constructor" << std::endl; }
		Final(const Final &) { std::cout << "Final COPY Constructor" << std::endl; }
		 virtual ~Final() { std::cout << "Final Destructor" << std::endl; }
		// virtual void funct(){ std::cout << "final!" << std::endl; }
		 void foo(){std::cout << "foo final" << std::endl;}
virtual void foo2(){std::cout << "foo2 final" << std::endl;}
};