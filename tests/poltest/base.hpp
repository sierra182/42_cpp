#include <iostream>

class Base
{
	protected:
	public:
		Base() { std::cout << "Base Constructor" << std::endl; }
		Base(const Base &) { std::cout << "Base COPY Constructor" << std::endl; }
		virtual ~Base() { std::cout << "Base destructor" << std::endl;};// = 0;// { std::cout << "Base Destructor" << std::endl; }
		void funct(){ std::cout << "base!" << std::endl; }
	
};

// inline Base::~Base() {}