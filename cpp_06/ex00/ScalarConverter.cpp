/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:19 by seblin            #+#    #+#             */
/*   Updated: 2024/08/03 15:06:02 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>
#include <string>

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

#include <cstdlib>
#include <limits>
#include <string>
void ScalarConverter::convert( std::string       & entry )
{	
	char 	ent_char;
	int		ent_int;
	float	ent_float;
	double	ent_double;

	std::stringstream ss(entry);

	if (entry == "inf" || entry == "inff")
	{
		std::cout << " char : impossible" << std::endl;
		std::cout << " int : impossible" << std::endl;
		std::cout << " float : inff" << std::endl;
		std::cout << " double : inf" << std::endl;
		return ;
	}
	if (entry == "-inff" || entry == "-inf")
	{
		std::cout << " char : impossible" << std::endl;
		std::cout << " int : impossible" << std::endl;
		std::cout << " float : -inff" << std::endl;
		std::cout << " double : -inf" << std::endl;
		return ;
	}
	if (entry == "nan" || entry == "nanf")
	{
		std::cout << " char : impossible" << std::endl;
		std::cout << " int : impossible" << std::endl;
		std::cout << " float : nanf" << std::endl;
		std::cout << " double : nan" << std::endl;
		return ;
	}

	if (entry.find_first_of('.') != std::string::npos && *--entry.end() == 'f')
	{
		ss.clear();
		ss.seekg(0, std::ios::beg);
		ss >> ent_float;
		if (ss)
		{	std::cout << "[FLOAT] :" << ent_float <<std::endl;
			std::cout << " char : '" << static_cast<char> (ent_float) << '\'' << std::endl;
			std::cout << " int: " << static_cast<int> (ent_float) << std::endl;
			std::string suff = ".0";		
			if (ent_float - static_cast<int>(ent_float)) 
				suff = "";

				
			std::cout << " float: " << static_cast<float> (ent_float) << suff + 'f'
				<< std::endl;
			std::cout << " double: " << static_cast<double> (ent_float) << suff
				<< std::endl;		
			return;
		}
		if(std::isnan(ent_float))
			std::cout << "NAAAAAAN" <<std::endl;
		std::cout << " char : impossible" << std::endl;
		std::cout << " int : impossible" << std::endl;
		std::cout << " float : nanf" << std::endl;
		std::cout << " double : nan" << std::endl;
		return ;	
	}
	if (entry.find_first_of('.') != std::string::npos)
	{		
		ss.clear();
		ss.seekg(0, std::ios::beg);
		ss >> ent_double;
		if (ss)
		{	std::cout << "[DOUBL] :" <<std::endl;
			std::cout << " char : '" << static_cast<char> (ent_double) << '\'' << std::endl;
			std::cout << " int: " << static_cast<int> (ent_double) << std::endl;	
			std::string suff = ".0";
			if (ent_double - static_cast<int>(ent_double)) 
				suff = "";
			std::cout << " float: " << static_cast<float> (ent_double) << suff + 'f'
				<< std::endl;
			std::cout << " double: " << static_cast<double> (ent_double) << suff
				<< std::endl;
			return;
		}
		std::cout << " char : impossible" << std::endl;
		std::cout << " int : impossible" << std::endl;
		std::cout << " float : nanf" << std::endl;
		std::cout << " double : nan" << std::endl;
		return ;
	}
	
	if (entry.length() == 1 && !std::isdigit(*entry.c_str()))
	{			
		ss.clear();
		ss.seekg(0, std::ios::beg);
		ss >> ent_char;
		if (ss)
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
		std::cout << " char : impossible" << std::endl;
		std::cout << " int : impossible" << std::endl;
		std::cout << " float : nanf" << std::endl;
		std::cout << " double : nan" << std::endl;
		return ;
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
	// if (entry == "nan")
	// {		
		std::cout << " char: impossible" << std::endl;
		std::cout << " int: impossible" << std::endl;
		std::cout << " float: nanf" << std::endl;
		std::cout << " double: nan" << std::endl;
		return;
	// }
	

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