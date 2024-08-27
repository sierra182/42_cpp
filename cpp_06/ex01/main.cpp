/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:25:00 by seblin            #+#    #+#             */
/*   Updated: 2024/08/27 14:56:55 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
#include "MyStyl.hpp"
#include <unistd.h>



int	main (void )
{
	MyStyl::addTest("serialization");
	
	MyStyl::addAction("create and init data struct");
	Data data;
		
	std::cout << std::endl;	
	MyStyl::addAction("display data:");
	std::cout << data;
	
	std::cout << std::endl << std::endl;
	MyStyl::addAction("\e[36mserialization:...\e[0m");
	uintptr_t sdata = Serializer::serialize(&data);

	sleep(1);	
	std::cout << std::endl;
	MyStyl::addAction("\e[95mdeserialization:...\e[0m");
	Data *data2 = Serializer::deserialize(sdata);
	
	sleep(1);
	std::cout << std::endl << std::endl;
	MyStyl::addAction("display data 2:");
	std::cout << *data2;
	
	MyStyl::addSubTest("are equals ?");
	sleep(1);
	std::cout << std::endl;
	if (&data == data2)
		std::cout << "\e[1;32m" << " > structures are equals" << "\e[0m"
			<< std::endl;
	else
		std::cout << " > structures are not equals" << std::endl;
	std::cout << std::endl;
	
	return (0);
}