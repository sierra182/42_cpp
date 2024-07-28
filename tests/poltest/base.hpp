#include <iostream>

class Base
{
		Base(const Base &) { std::cout << "Base COPY Constructor" << std::endl; }
		void funct(){ std::cout << "base!" << std::endl; }
	protected:
		Base() { std::cout << "Base Constructor" << std::endl; }
		 ~Base() { std::cout << "Base destructor" << std::endl;};// = 0;// { std::cout << "Base Destructor" << std::endl; }
	public:
	
};

// inline Base::~Base() {}