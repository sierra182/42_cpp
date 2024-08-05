/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:25:00 by seblin            #+#    #+#             */
/*   Updated: 2024/08/05 13:27:11 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

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

	initData(data);
	std::cout << std::endl << "----data:" << std::endl << std::endl;
	displayData(data);
	
	sdata = Serializer::serialize(&data);
	std::cout << std::endl << "serialization:..." << std::endl;
	
	data2 = Serializer::deserialize(sdata);

	std::cout << std::endl << "deserialization:..." << std::endl;
	
	std::cout << std::endl << "----data2:" << std::endl << std::endl;
	displayData(*data2);

	std::cout << std::endl;
	if (&data == data2)
		std::cout << "structures are equals" << std::endl;
	else
		std::cout << "structures are not equals" << std::endl;
	std::cout << std::endl;
	return (0);
}