/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/27 14:57:59 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void )
{
	this->myShInt = 30000;
	this->myInt = 35000;
	this->myDouble = 42.2;
	this->myFloat = 42.1f;
	this->myChar = 'z';
	this->myCString = "bravo";
	this->myString = "houlala";
	return ;
}

Data::~Data( void )
{
	return ;
}

Data::Data( const Data & src )
{
	*this = src;
	return ;
}

Data & Data::operator=( const Data & rhs )
{
	if (this != &rhs)
	{		
		if (this->myShInt != rhs.myShInt)
			this->myShInt = rhs.myShInt;
		if (this->myInt != rhs.myInt)
			this->myInt = rhs.myInt;
		if (this->myDouble != rhs.myDouble)
			this->myDouble = rhs.myDouble;			
		if (this->myFloat != rhs.myFloat)
			this->myFloat = rhs.myFloat	;		
		if (this->myChar != rhs.myChar)
			this->myChar = rhs.myChar;			
		if (this->myCString != rhs.myCString)
			this->myCString = rhs.myCString;			
		if (this->myString != rhs.myString)
			this->myString = rhs.myString;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & lhs, const Data & rhs)
{
	std::cout <<std::endl;
	lhs << " char: \t\t" << rhs.myChar << std::endl;
	lhs << " short int: \t" << rhs.myShInt << std::endl;
	lhs << " int: \t\t" << rhs.myInt << std::endl;
	lhs << " double: \t" << rhs.myDouble << std::endl;
	lhs << " string: \t" << rhs.myString << std::endl;
	lhs << " char*: \t" << rhs.myCString << std::endl;
	lhs << " float: \t" << rhs.myFloat << std::endl;	
	return (lhs);
}	
