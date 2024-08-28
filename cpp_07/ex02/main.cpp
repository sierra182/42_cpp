#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#include "MyStyl.hpp"

#define MAX_VAL 750

void other_tests()
{
    MyStyl::addTest("empty array");

    MyStyl::addAction("create empty array");
    MyStyl::addAction("Array<int> str1(0)");
	Array<int> str1(0);
    std::cout << std::endl;
	try {
        MyStyl::addAction("try acces to empty array");       
        MyStyl::addAction("str1[0]");
		str1[0];
	}
	catch (const std::exception & e)
		{ MyStyl::addWhat(e.what()); }

	Array<Array<int> > inception(MAX_VAL);
	
    MyStyl::addTest("create n element default initialized");
    MyStyl::addAction("Array<const int> definit(42)");
    std::cout << std::endl;
	Array<const int> definit(42);
	for (int i = 0; i < 42; i++)
			std::cout << definit[i] << " ";

	std::cout << std::endl << std::endl;
    
    MyStyl::addTest("copy array with different sizes - str1(maxVal) - \
str2(42)", 0);
    MyStyl::addSubTest("and finnaly try acces to str1[MAX_VAL - 1]");

    MyStyl::addAction("create str1");
    MyStyl::addAction("str1(MAX_VAL)");    
	Array<std::string> str(MAX_VAL);

    std::cout << std::endl;
    MyStyl::addAction("create str2");
    MyStyl::addAction("str2(42)");
	Array<std::string> str2(42);

    std::cout << std::endl;
    MyStyl::addAction("str1 = str2");
    MyStyl::addAction("str2[2] = \"haha\"");
    std::cout << std::endl;
    std::cout << std::endl;
    
	str = str2;
	str2[2] = "haha ";
	std::cout << " str2 :" << std::endl << " ";
	for (int i = 0; i < 42; i++)
		std::cout << str2[i] << i << " ";
    std::cout << std::endl;
	std::cout << std::endl << " str1 :" << std::endl << " ";
	try {
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << str[i] << i << " ";    
	}
	catch (const std::exception & e)
		{ std::cout << std::endl; MyStyl::addWhat(e.what()); }
	std::cout << std::endl;

	Array<int> t;
	Array<int> t2(26);
	t = t2;
}

int main(int, char**)
{
    MyStyl::addTest("mandatory");
    
    MyStyl::addAction("create array");
    MyStyl::addAction("Array<int> numbers(MAX_VAL)");
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
        MyStyl::addSubTest("negative index");
        MyStyl::addAction("numbers[-2] = 0");
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
        { MyStyl::addWhat(e.what()); }
    try
    {
        MyStyl::addSubTest("index too hight");
        MyStyl::addAction("numbers[MAX_VAL] = 0");
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
        { MyStyl::addWhat(e.what()); }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	other_tests();
    return 0;
}
