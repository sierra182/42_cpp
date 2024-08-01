/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:19 by seblin            #+#    #+#             */
/*   Updated: 2024/08/01 18:25:20 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
	
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

static void convert( std::string const & entry )
{
	std::cout << std::string(entry) << std::endl;
	std::cout << static_cast<int>(entry) << std::endl;
}