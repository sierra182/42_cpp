/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:19 by seblin            #+#    #+#             */
/*   Updated: 2024/08/02 17:01:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>

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
	char 	ent_char;
	int		ent_int;
	float	ent_float;
	double	ent_double;

	std::stringstream ss(entry);
	// std::cout << entry <<std::endl;
	if (entry.find_first_of('.') != std::string::npos && *--entry.end() == 'f')
	{
		ss.clear();
		ss.seekg(0, std::ios::beg);
		ss >> ent_float;
		if (ss)
		{	std::cout << "[FLOAT] :" <<std::endl;
			std::cout << " char : '" << static_cast<char> (ent_float) << '\'' << std::endl;
			std::cout << " int: " << static_cast<int> (ent_float) << std::endl;
			std::cout << " float: " << static_cast<float> (ent_float) << ".0f" 
				<< std::endl;
			std::cout << " double: " << static_cast<double> (ent_float) << ".0"
				<< std::endl;
			return;
		}

	}
	
	ss.clear();
	ss.seekg(0, std::ios::beg);
	ss >> ent_double;
	if (ss && entry.find_first_of('.') != std::string::npos)
	{	std::cout << "[DOUBL] :" <<std::endl;
		std::cout << " char : '" << static_cast<char> (ent_double) << '\'' << std::endl;
		std::cout << " int: " << static_cast<int> (ent_double) << std::endl;
		std::cout << " float: " << static_cast<float> (ent_double) << ".0f" 
			<< std::endl;
		std::cout << " double: " << static_cast<double> (ent_double) << ".0"
			<< std::endl;
		return;
	}
	
	ss.clear();
	ss.seekg(0, std::ios::beg);
	ss >> ent_char;
	if (ss && entry.length() == 1 && !std::isdigit(*entry.c_str()))
	{	std::cout << "[CHAR] :" <<std::endl;
	
		if (std::isprint(ent_char))			
			std::cout << " char : '" << static_cast<char>(ent_char) << '\'' << std::endl;
		else
			std::cout << " char : Non displayable" << std::endl;

		std::cout << " int: " << static_cast<int> (ent_char) << std::endl;
		std::cout << " float: " << static_cast<float> (ent_char) << ".0f" 
			<< std::endl;
		std::cout << " double: " << static_cast<double> (ent_char) << ".0"
			<< std::endl;		
		return;
	}
	ss.clear();
	ss.seekg(0, std::ios::beg);
	ss >> ent_int;
	if (ss)
	{	std::cout << "[INT] :" <<std::endl;
		if (std::isprint(ent_int))			
			std::cout << " char : '" << static_cast<char>(ent_int) << '\'' << std::endl;
		else
			std::cout << " char: Non displayable" << std::endl;
		std::cout << " int: " << static_cast<int> (ent_int) << std::endl;
		std::cout << " float: " << static_cast<float> (ent_int) << ".0f" 
			<< std::endl;
		std::cout << " double: " << static_cast<double> (ent_int) << ".0"
			<< std::endl;
		return;
	}
	if (entry == "nan")
	{		
		std::cout << " char: impossible" << std::endl;
		std::cout << " int: impossible" << std::endl;
		std::cout << " float: nanf" << std::endl;
		std::cout << " double: nan" << std::endl;
		return;
	}
	

	// 	std::cout << "fail!" << std::endl;
	// ss >> ent;
	// if (ss)
	// 	std::cout << ent << std::endl;
	// else
	// 	std::cout << "fail!" << std::endl;
	// ss.clear();
	// ss.ignore();
	// ss >> ent;
	// if (ss)
	// 	std::cout << ent << std::endl;
	// else
	// 	std::cout << "fail!" << std::endl;
}