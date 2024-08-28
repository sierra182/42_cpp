/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:01:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/28 13:36:19 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "MyStyl.hpp"

int main( void )
{
	std::cout << std::endl;
	int a = 2;
	int b = 3;
	myFuncts::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << myFuncts::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << myFuncts::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	myFuncts::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << myFuncts::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << myFuncts::max( c, d ) << std::endl;	
	std::cout << std::endl;

	MyStyl::addTest("my own tests", 0);	

	{
		MyStyl::addSubTest("type: int");
			
		int a = 2;
		int b = 4;
		
		std::cout << "\e[32m";
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call swap..." << std::endl;
		myFuncts::swap(a, b);
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		
		std::cout << std::endl;
		std::cout << "\e[1m a = b\e[0;32m" << std::endl;
		a = b;
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		std::cout << "\e[0m";
	}	
	{
		MyStyl::addSubTest("type: char");
			
		char a = 'y';
		char b = 'z';

		std::cout << "\e[36m";
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call swap..." << std::endl;
		myFuncts::swap(a, b);
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		
		std::cout << std::endl;
		std::cout << "\e[1m a = b\e[0;36m" << std::endl;
		a = b;
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		std::cout << "\e[0m";
	}
	{
		MyStyl::addSubTest("type: float");
			
		float a = 42.2f;
		float b = 17.9f;

		std::cout << "\e[35m";
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call swap..." << std::endl;
		myFuncts::swap(a, b);
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		
		std::cout << std::endl;
		std::cout << "\e[1m a = b\e[0;35m" << std::endl;
		a = b;
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		std::cout << "\e[0m";
	}
	{
		MyStyl::addSubTest("type: string");
			
		std::string a = "morue";
		std::string b = "zombi";

		std::cout << "\e[31m";
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call swap..." << std::endl;
		myFuncts::swap(a, b);
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		
		std::cout << std::endl;
		std::cout << "\e[1m a = b\e[0;31m" << std::endl;
		a = b;
		std::cout << std::endl;
		std::cout << " a: " << a << " b: " << b << std::endl;
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		std::cout << "\e[0m";
	}
	{
		MyStyl::addSubTest("type: const int");
			
		const int a = -42;
		const int b = 122;

		std::cout << "\e[32m";
		std::cout << " a: " << a << " b: " << b << std::endl;
		
		std::cout << std::endl;
		std::cout << " call min: " << myFuncts::min(a, b) << std::endl;
		std::cout << " call max: " << myFuncts::max(a, b) << std::endl;
		
		std::cout << std::endl;
	
	}
	std::cout << std::endl;
	return (0);	
}
