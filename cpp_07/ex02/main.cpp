#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#define MAX_VAL 27//!750

int main(int, char**)
{
	// int _array[] = {15, 16};
	// _array;
	// {
	// 	int * _array = new int[2];//{42, 43};
	// 	_array[0] = 1;
	// 	_array[1] = 2;
	// 	int *& _array_ref = _array;
	// 	std::cout << _array_ref[1] << std::endl;
	// }
	// {
	// 	int _array[2];
	// 	_array[0] = 1;
	// 	_array[1] = 2;
	// 	int *_arr_ptr =  (int *){_array};
	// 	int *& _array_ref = _arr_ptr;
	// 	std::cout << _array_ref[1] << std::endl;
	// }
	// {
	// 	int _array[2];//{42, 43};
	// 	_array[0] = 1;
	// 	_array[1] = 2;
	// 	int (&_array_ref)[2] = _array;
	// 	std::cout << _array_ref[1] << std::endl;
	// }
	// {

	// 	int _array[] = {15, 16};
	// 	std::cout << _array[1] << std::endl;
		
	// }
// int n = 42;
// 	Array<int> * truc = new Array<int>(n);
// 	(*truc)[1] = 1664;
// 	std::cout << "value: " << (*truc)[1] << std::endl;
// 	// Array<int> turc;
// 	// std::cout << turc.size() << std::endl;

// 	delete truc; truc = NULL;

			// int n = 4200;
			// Array<int> * truc = new Array<int>[n]();

			// // Array<int> turc;

			// for (int i = 0; i < n; i++)
			// 	std::cout << truc->test;

			// std::cout <<std::endl;
			// std::cout <<std::endl;

			// // for (int i = 0; i < n; i++)
			// 	// std::cout << turc.test;

			// 		std::cout <<std::endl;
			// delete[] truc; truc = NULL;
		
	Array<float> * nu = new Array<float>(3);

	// (*nu)[0] = 6.2f;
	std::cout << "nu: " << (*nu)[2] << std::endl;
// delete nu;
Array<float> nu3(42);
*nu = nu3;
nu3 = *nu;
std::cout << "problem?: " << std::endl;
return 0;
// int e[] = {1, 2};
// std::cout << e[1] << std::endl;

// int * f = new int[4]();
// std::cout << f[1] << std::endl;
// return 0;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		std::cout << "value0 : " << value << std::endl;//!
		std::cout << "value1 : " << numbers[i] << std::endl;//!
		std::cout << "value2 : " << mirror[i] << std::endl;//!		
    }
    //SCOPE
    {
	
        Array<int> tmp = numbers;
	
        Array<int> test(tmp);

		std::cout << "tmp size : " << tmp.size() << std::endl;//!
		std::cout << "test size : " << test.size() << std::endl;//!
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "tmp : " << tmp[i] << std::endl;//!
			std::cout << "test : " << test[i] << std::endl;//!		
		}
std::cout << "plantage before" << std::endl;
    }
std::cout << "plantage after" << std::endl;


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


	bool shal = false;
	   for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] == numbers[i])
        {
			shal = true;
            std::cerr << "you've made a shallow copy bitch!!" << std::endl;
            return 1;
        }
    }
	if (!shal)
		 std::cerr << "you've made a deep copy darling!!" << std::endl;
    delete [] mirror;//
    return 0;
}