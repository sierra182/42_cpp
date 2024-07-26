#include "base.hpp"
#include <cstdlib>
class Interm : public Base
{
	using Base::funct;
	public:
		
		Interm() { std::cout << "Interm Constructor" << std::endl; }
		Interm(const Interm &) { std::cout << "Interm COPY Constructor" << std::endl; }
		virtual ~Interm() {std::cout << "Interm Destructor" << std::endl;}
	
};