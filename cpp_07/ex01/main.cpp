/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:51:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/28 12:13:51 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include "MyStyl.hpp"
#include <unistd.h>

int main (void )
{
	MyStyl::addTest("my own tests", 0);
			
	{
		MyStyl::addSubTest("type: int");	
			
		std::cout << std::endl;
		int arr[] = {42, 24, 21};
		iter(arr, 3, myfunct);
		usleep(250000);
	}
	{	
		MyStyl::addSubTest("type: char");	
		
		std::cout << std::endl;
		char arr[] = {'z', 's', 'h'};
		iter(arr, 3, myfunct);
		usleep(250000);
	}	
	{	
		MyStyl::addSubTest("type: float");	
		
		std::cout << std::endl;
		float arr[] = {42.2f, 0.1f, 974.974f};
		iter(arr, 3, myfunct);
		usleep(250000);
	}
	{	
		MyStyl::addSubTest("type: double");
			
		std::cout << std::endl;
		double arr[] = {42.2, 0.1, 974.974};
		iter(arr, 3, myfunct);
		usleep(250000);
	}
	{	
		MyStyl::addSubTest("type: string");
			
		std::cout << std::endl;	
		std::string arr[] = {"je", "souffre", "d'un", "manque", "cruel",
			"d'imagination"};
		iter(arr, 6, myfunct);
	}	
	std::cout << std::endl;
	return (0);
}