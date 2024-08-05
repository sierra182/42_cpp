/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:01:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/05 21:30:36 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
int foo(T ki, int ku)
{
	std::cout << "1 long time" << std::endl;
	return 42;
}
template <>
int foo(int ki, int ku)
{
	std::cout << "2 long time" << std::endl;
	return 42;
}
template <int , typename T>
int foo(int ki, T ku)
{
	std::cout << "3 long time" << std::endl;
	return 42;
}
// template <typename T>
// class truc{};
// template <>
// class  truc<int>{};
//  template < typename T = int >
//  const T teste( const T & t )
// {
	
// 	return t;
// }
// template < typename T = int >
// class test
// {	
// 	public:
// 	test(void){};
// 	explicit test( const T & t )
// 	{
// 		(void) t;
// 		std::cout << "whi" << t  << std::endl;
// 		return ;
// 	}
// } ;

// class Test {
// 	static const int value = 41;;
// public:
// 	operator int( void ) const{
// 		return value;
// 	}
//      Test(int t) {
//         (void)t;
//         std::cout << "whi" << std::endl;
//     }
// };

// void func(Test t) {
//     // Do something
// }
int main( void )
{
	foo('a', 42);
	foo(42, 42);
	foo(42, 42.0f);
	// test<> te(42.2);
	// Test te = 41;
	// int fr = te;
	// std::cout << fr <<std::endl; 
	//   Test te1 = 42;   // Erreur : le constructeur est explicite
    // Test te2(42);    // Fonctionne : le constructeur est appelé explicitement
    // func(42);  // Erreur : conversion implicite bloquée
	// #define max(x, y) (x > y ? x : y)
	// max(foo(), foo());
	// char a = 'a';
	// test te(a);
	// std::cout << test(42) << std::endl;
	// std::cout << max(6,9) << std::endl;
	// int a = 2;
	// int b = 3;
	// ::swap( a, b );
	// std::cout << "a = " << a << ", b = " << b << std::endl;
	// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	// std::string c = "chaine1";
	// std::string d = "chaine2";
	// ::swap(c, d);
	// std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	// return 0;
}