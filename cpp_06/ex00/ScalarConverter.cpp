/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:19 by seblin            #+#    #+#             */
/*   Updated: 2024/08/02 11:47:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter( void )
{
	return ;
}

ScalarConverter::~ScalarConverter( void )
{
	return ;
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
	
	return ;
}

ScalarConverter & ScalarConverter::operator=( const ScalarConverter & rhs )
{
	(void) rhs;		
	return (*this);
}

void ScalarConverter::convert( std::string const & entry )
{	
	int ent;

	std::stringstream ss(entry);
	ss >> ent;
	if (ss)
		std::cout << ent << std::endl;
	else
		std::cout << "fail!" << std::endl;
	ss >> ent;
	if (ss)
		std::cout << ent << std::endl;
	else
		std::cout << "fail!" << std::endl;
	ss.clear();
	ss.ignore();
	ss >> ent;
	if (ss)
		std::cout << ent << std::endl;
	else
		std::cout << "fail!" << std::endl;
}