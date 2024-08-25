/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:25:00 by seblin            #+#    #+#             */
/*   Updated: 2024/08/25 14:22:59 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
#include "MyStyl.hpp"
#include <unistd.h>

void displayData( Data & data )
{
	std::cout << ' ' << data.myChar << std::endl;
	std::cout << ' ' << data.myShInt << std::endl;
	std::cout << ' ' << data.myInt << std::endl;
	std::cout << ' ' << data.myDouble << std::endl;
	std::cout << ' ' << data.myString << std::endl;
	std::cout << ' ' << data.myCString << std::endl;
	std::cout << ' ' << data.myFloat << std::endl;
}

void initData( Data & data )
{
	data.myShInt = 30000;
	data.myInt = 35000;
	data.myDouble = 42.2;
	data.myFloat = 42.1f;
	data.myChar = 'z';
	data.myCString = "bravo";
	data.myString = "houlala";
}

int	main (void )
{
	Data data;
	Data *data2;
	uintptr_t sdata;

	MyStyl::addTest("serialization");
	
	MyStyl::addAction("create and init data struct");
	initData(data);
	
	std::cout << std::endl;	
	MyStyl::addAction("display data:");
	displayData(data);
	
	std::cout << std::endl;
	MyStyl::addAction("\e[36mserialization:...\e[0m");
	sdata = Serializer::serialize(&data);

	sleep(1);	
	std::cout << std::endl;
	MyStyl::addAction("\e[95mdeserialization:...\e[0m");
	data2 = Serializer::deserialize(sdata);
	
	sleep(1);
	std::cout << std::endl;
	MyStyl::addAction("display data 2:");
	displayData(*data2);

	MyStyl::addSubTest("are equals ?");
	sleep(1);
	std::cout << std::endl;
	if (&data == data2)
		std::cout << "\e[1;32m" << " > structures are equals" << "\e[0m" << std::endl;
	else
		std::cout << " > structures are not equals" << std::endl;
	std::cout << std::endl;
	
	return (0);
}