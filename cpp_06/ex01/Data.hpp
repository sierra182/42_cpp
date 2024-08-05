/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:12 by seblin            #+#    #+#             */
/*   Updated: 2024/08/05 09:47:39 by seblin           ###   ########.fr       */
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
	
	short int myShInt;
	int myInt;
	double myDouble;
	float myFloat;
	char myChar;
	char *myCString;
	std::string myString;		
};