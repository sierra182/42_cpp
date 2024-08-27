/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:12 by seblin            #+#    #+#             */
/*   Updated: 2024/08/27 14:46:43 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

struct Data
{
	Data( void );
	virtual ~Data( void );
	Data( const Data & src );
	Data & operator=( const Data & rhs );
		
	short int		myShInt;
	int 			myInt;
	double			myDouble;
	float			myFloat;
	char			myChar;
	const char *	myCString;
	std::string 	myString;

	
	// void displayData( Data & data )
	// {
	// 	std::cout << ' ' << data.myChar << std::endl;
	// 	std::cout << ' ' << data.myShInt << std::endl;
	// 	std::cout << ' ' << data.myInt << std::endl;
	// 	std::cout << ' ' << data.myDouble << std::endl;
	// 	std::cout << ' ' << data.myString << std::endl;
	// 	std::cout << ' ' << data.myCString << std::endl;
	// 	std::cout << ' ' << data.myFloat << std::endl;
	// }

	// void initData( Data & data )
	// {
	// 	data.myShInt = 30000;
	// 	data.myInt = 35000;
	// 	data.myDouble = 42.2;
	// 	data.myFloat = 42.1f;
	// 	data.myChar = 'z';
	// 	data.myCString = "bravo";
	// 	data.myString = "houlala";
	// }		
};

std::ostream & operator<<(std::ostream & lhs, const Data & rhs);
