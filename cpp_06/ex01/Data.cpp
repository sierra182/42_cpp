/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/05 13:19:24 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void )
{
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
