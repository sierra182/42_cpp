// #include "base.hpp"
#include "final.hpp"

int main()
{
	// Base base;
	// std::cout << std::endl;
	// base.funct();
	// std::cout << std::endl;

	// {
	// 	Base *base = new Interm();
	// 	std::cout << std::endl;
	// 	base->funct();
	// 	std::cout << std::endl;
	// }
	// {
	// 	Base *base = new Final();
	// 	std::cout << std::endl;
	// 	base->funct();
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << std::endl;
	// 	Interm inter;
	// 	std::cout << std::endl << "inter declared" << std::endl;
	// 	Base *base =  &inter;
	// 	std::cout << "base * declared" << std::endl;
	// 	std::cout << std::endl;
	// 	base->funct();
	// 	std::cout << std::endl;
	// }
	int a,  b = 2, c;
	// b = 1
	std::cout << b <<  std::endl;
	// {
	// 	std::cout << std::endl;	
	// 	Interm *inter = new Interm();	
	// 	Base *base = inter;
	// 	// Base rebase = *inter;
	// 	std::cout << "base * declared with new" << std::endl;
	// 	std::cout << std::endl;
	// 	base->funct();
	// 	delete inter;
	// 	std::cout << "deleted" << std::endl;
	// }
	{
		std::cout << std::endl;	
		Interm *inter = new Interm();	
		// Base base = *inter;
		// Base rebase = *inter;
		std::cout << "base * declared with new" << std::endl;
		std::cout << std::endl;
		// base.funct();
		delete inter;
		std::cout << "deleted" << std::endl;
	}
	 std::cout << "ended scope" <<  std::endl;
	// {
	// 	Final fin;
	// 	std::cout << "fin declared" << std::endl;
	// 	Base *base = &fin;
	// 	std::cout << "base * declared" << std::endl;
	// 	std::cout << std::endl;
	// 	base->funct();
	// 	std::cout << std::endl;
	// }
std::cout << std::endl;
}