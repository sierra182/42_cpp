#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

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
int n = 420;
	Array<int> * truc = new Array<int>(n);
	std::cout << truc->size() << std::endl;
	// Array<int> turc;
	// std::cout << turc.size() << std::endl;

	delete truc; truc = NULL;

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

    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
    // return 0;
}