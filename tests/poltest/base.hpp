#include <iostream>

class Base
{
	public:
		Base(const Base &) { std::cout << "Base COPY Constructor" << std::endl; }
		void funct(){ std::cout << "base!" << std::endl; }
		Base() { std::cout << "Base Constructor" << std::endl; }
		 ~Base() { std::cout << "Base destructor" << std::endl;};// = 0;// { std::cout << "Base Destructor" << std::endl; }
	
		 void foo(){std::cout << "foo base" << std::endl;}
	protected:
	
};

// inline Base::~Base() {}