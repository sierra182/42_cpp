/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:46:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/05 15:48:00 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void)
{	
	int rand = std::rand() % 3;
	switch (rand)
	{
		case 0:
			return new A();			
		case 1:
			return new B();
		case 2:
			return new C();		
	}
	return (NULL);
}

void identify(Base* p)
{
	std::cout << "\e[1;32m ⚝ \e[0m identification with pointer:" << std::endl
		<< std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << " the actual type is : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << " the actual type is : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << " the actual type is : C" << std::endl;
}

void identify(Base& p)
{
	std::cout << std::endl << "\e[1;34m & \e[0m identification with reference:"  << std::endl
		<< std::endl;
	try
	{
		dynamic_cast<A&>(p);
		std::cout << " the actual type is : A" << std::endl;
	}
	catch (const std::exception & e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << " the actual type is : B" << std::endl;
		}
		catch (const std::exception & e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << " the actual type is : C" << std::endl;
			}
			catch (const std::exception & e)
			{
				std::cerr << "Oops" << std::endl;
			}
		}	
	}
}

int main( void )
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	std::cout << std::endl;
	Base * rand = generate();
	identify(rand);
	identify(*rand);
	std::cout << std::endl;
	delete rand;
	return (0);
}