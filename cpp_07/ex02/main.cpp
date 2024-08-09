#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 750

void other_tests()
{
	std::cout << std::endl;
	std::cout << " *****others tests*****" << std::endl
		<< std::endl;
	std::cout << " create empty array" << std::endl;
	Array<int> str1(0);
	try {
		std::cout << " try acces to empty array" << std::endl;
		str1[0];
	}
	catch (const std::exception & e)
		{ std::cerr << e.what() << std::endl; }
	Array<Array<int> > inception(MAX_VAL);
	std::cout << std::endl;
	std::cout << " test create n element default initialized" << std::endl
		<< " ";
	Array<const int> definit(42);
	for (int i = 0; i < 42; i++)
			std::cout << definit[i] << " ";

	std::cout << std::endl << std::endl;
	std::cout << " test copy array with different sizes - str1(maxVal) - \
str2(42)" << std::endl;
	Array<std::string> str(MAX_VAL);
	Array<std::string> str2(42);
	std::cout << " str1 = str2 " << std::endl << " str2[2] = \"haha\""
		<< std::endl << std::endl;
	str = str2;
	str2[2] = "haha ";
	std::cout << " str2 :" << std::endl << " ";
	for (int i = 0; i < 42; i++)
		std::cout << str2[i] << i << " ";
	std::cout << std::endl << " str1 :" << std::endl << " ";
	try {
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << str[i] << i << " ";
	}
	catch (const std::exception & e)
		{ std::cerr << std::endl << e.what() << std::endl; }
	std::cout << std::endl;

	Array<int> t;
	Array<int> t2(26);
	t = t2;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	other_tests();
    return 0;
}
