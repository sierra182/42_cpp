#include <iostream>

class Base
{
	public:
		Base() { std::cout << "Base Constructor" << std::endl; }
		Base(const Base &) { std::cout << "Base COPY Constructor" << std::endl; }
		 virtual ~Base() = 0;// { std::cout << "Base Destructor" << std::endl; }
		virtual void funct(){ std::cout << "base!" << std::endl; }
	
};

inline Base::~Base() {}