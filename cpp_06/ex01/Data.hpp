/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:12 by seblin            #+#    #+#             */
/*   Updated: 2024/08/05 12:42:46 by seblin           ###   ########.fr       */
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
	bool operator==( const Data & rhs );
	
	short int		myShInt;
	int 			myInt;
	double			myDouble;
	float			myFloat;
	char			myChar;
	const char *	myCString;
	std::string 	myString;		
};