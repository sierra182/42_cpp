#include "base.hpp"
#include <cstdlib>
class Interm : public Base
{
		void funct() { std::cout << "interm!" << std::endl; this->mal = malloc(1);}
	public:
		void *mal;
		Interm() { std::cout << "Interm Constructor" << std::endl; }
		Interm(const Interm &) { std::cout << "Interm COPY Constructor" << std::endl; }
		// virtual ~Interm() {Base::~Base(); std::cout << "Interm Destructor" << std::endl; free(this->mal);}
	
};