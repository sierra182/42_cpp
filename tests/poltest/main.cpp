
#include "final.hpp"


int main()
{
	// {	
	// 	Base * test = new Base();
	// 	test->foo();		
	// }
	// {	
	// 	Base * test = new Interm();
	// 	test->foo();
		
	// }
	// {
	// 	Base * test = new Final();
	// 	test->foo();	
	// }
	
	{
		Interm * test = new Interm();
		test->foo();	
		test->foo2();	
	}
	{
		Interm * test = new Final();
		test->foo();	
		test->foo2();	
	}
}