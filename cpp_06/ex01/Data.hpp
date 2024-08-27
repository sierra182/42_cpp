/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:12 by seblin            #+#    #+#             */
/*   Updated: 2024/08/27 14:57:45 by svidot           ###   ########.fr       */
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
};

std::ostream & operator<<(std::ostream & lhs, const Data & rhs);
