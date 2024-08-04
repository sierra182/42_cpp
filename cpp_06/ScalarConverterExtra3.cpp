/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterExtra.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:59:25 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 10:20:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iostream>

bool ScalarConverter::isSpecialCase( std::string entry )
{
	return (entry == "inf" || entry == "inff"
		|| entry == "+inf" || entry == "+inff"
		|| entry == "-inff" || entry == "-inf"
		|| entry == "nan" || entry == "nanf");
}

void ScalarConverter::specialCase( std::string const & entry )
{		
	std::cout << " char : impossible" << std::endl;
	std::cout << " int : impossible" << std::endl;	
	if (entry == "inf" || entry == "inff"
		|| entry == "+inf" || entry == "+inff")
	{	
		std::cout << " float : inff" << std::endl;
		std::cout << " double : inf" << std::endl;		
	}
	else if (entry == "-inff" || entry == "-inf")
	{
		std::cout << " float : -inff" << std::endl;
		std::cout << " double : -inf" << std::endl;	
	}
	else if (entry == "nan" || entry == "nanf")
	{	
		std::cout << " float : nanf" << std::endl;
		std::cout << " double : nan" << std::endl;	
	}
}

void ScalarConverter::displayAllImpossible( void ) 
{
	std::cout << " char : impossible" << std::endl;
	std::cout << " int : impossible" << std::endl;
	std::cout << " float : impossible" << std::endl;
	std::cout << " double : impossible" << std::endl;
}
#include <iomanip>
void ScalarConverter::floatCase( std::string entry )
{
	std::stringstream	ss(entry);
	float				ent_float;
	
	ss >> ent_float;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered an float \e[0;35m" << std::endl
			<<std::endl;	
		if (ent_float >= 0 && ent_float <= 127)
		{
			if (std::isprint(ent_float))			
				std::cout << " char : '" << static_cast<char> (ent_float)
					<< '\'' << std::endl;
			else
				std::cout << " char : Non displayable" << std::endl;			
		}
		else			
			std::cout << " char : impossible" << std::endl;
			
		if (ent_float <= std::numeric_limits<int>::max()
			&& ent_float >=  std::numeric_limits<int>::min())
			std::cout << " int: " << static_cast<int> (ent_float) << std::endl;
		else
			std::cout << " int: impossible " << std::endl;
			
		// std::string suff = ".0";		
		if (ent_float == std::floor(ent_float))
			{
				// std::cout << "is dec" << std::endl;
				std::cout << std::fixed << std::setprecision(1) << " float: " << static_cast<float> (ent_float) <<  'f'
			<< std::endl;
		std::cout << std::fixed << std::setprecision(1) << " double: " << static_cast<double> (ent_float) << std::endl;
			}
			else {

		std::cout << std::fixed << " float: " << static_cast<float> (ent_float) << 'f'
			<< std::endl;
		std::cout << std::fixed << " double: " << static_cast<double> (ent_float) <<  std::endl;			
				
			}
			// suff = "";			
	}	
	else displayAllImpossible();
}	

void ScalarConverter::doubleCase( std::string entry )
{
	std::stringstream	ss(entry);
	double				ent_double;
	
	ss >> ent_double;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered a double \e[0;34m" << std::endl
			<<std::endl;	
		if (ent_double >= 0 && ent_double <= 127)
		{
			if (std::isprint(ent_double))			
				std::cout << " char : '" << static_cast<char> (ent_double)
					<< '\'' << std::endl;
			else
				std::cout << " char : Non displayable" << std::endl;
		}
		else			
			std::cout << " char : impossible" << std::endl;
			
		if (ent_double <= std::numeric_limits<int>::max()
			&& ent_double >=  std::numeric_limits<int>::min())
			std::cout << " int: " << static_cast<int> (ent_double)
				<< std::endl;
		else
			std::cout << " int: impossible " << std::endl;	
		std::string suff = ".0";
		
		if (ent_double == std::floor(ent_double))
			{
				// std::cout << "is dec" << std::endl;
				std::cout << std::fixed << std::setprecision(1) << " float: " << static_cast<float> (ent_double) <<  'f'
			<< std::endl;
		std::cout << std::fixed << std::setprecision(1) << " double: " << static_cast<double> (ent_double) << std::endl;
			}
			else {

		std::cout << std::fixed << " float: " << static_cast<float> (ent_double) << 'f'
			<< std::endl;
		std::cout << std::fixed << " double: " << static_cast<double> (ent_double) <<  std::endl;			
				
			}	
	}
	else displayAllImpossible();	
}

void ScalarConverter::charCase( std::string entry )
{
	std::stringstream	ss(entry);
	char				ent_char;

	ss >> ent_char;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered a char \e[0;33m" << std::endl
			<<std::endl;		
		if (std::isprint(ent_char))			
			std::cout << " char : '" << static_cast<char> (ent_char) <<
			'\'' << std::endl;
		else
			std::cout << " char : Non displayable" << std::endl;	
		
		std::cout << " int: " << static_cast<int> (ent_char) << std::endl;
		std::cout << " float: " << static_cast<float> (ent_char) << ".0f" 
			<< std::endl;
		std::cout << " double: " << static_cast<double> (ent_char) << ".0"
			<< std::endl;		
	}
	else displayAllImpossible();
}

void ScalarConverter::intCase( std::string entry )
{
	std::stringstream	ss(entry);
	int					ent_int;

	ss >> ent_int;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered an int \e[0;31m" << std::endl
			<<std::endl;
		if (ent_int >= 0 && ent_int <= 127)
		{
			if (std::isprint(ent_int))			
				std::cout << " char : '" << static_cast<char> (ent_int) <<
					'\'' << std::endl;
			else
				std::cout << " char : Non displayable" << std::endl;
		}
		else			
			std::cout << " char : impossible" << std::endl;
			
		if (ent_int <= std::numeric_limits<int>::max()
			&& ent_int >= std::numeric_limits<int>::min())
				std::cout << " int: " << static_cast<int> (ent_int)
					<< std::endl;
			else
				std::cout << " int: impossible " << std::endl;
				
		std::cout << " float: " << static_cast<float> (ent_int) << ".0f" 
			<< std::endl;
		std::cout << " double: " << static_cast<double> (ent_int) << ".0"
			<< std::endl;
	}	
	else 
	{
			std::cout << " char: impossible " << std::endl;
			std::cout << " int: impossible " << std::endl;
			float ent_float;
			ss.clear();
			ss.seekg(0, std::ios::beg);
			ss >> ent_float ;
			if (ss)
			{
				
				if (ent_float == std::floor(ent_float))
				{
					// std::cout << "is dec" << std::endl;
					std::cout << std::fixed << std::setprecision(1) << " float: " << static_cast<float> (ent_float) <<  'f'
				<< std::endl;
			std::cout << std::fixed << std::setprecision(1) << " double: " << static_cast<double> (ent_float) << std::endl;
				}
				else {

			std::cout << std::fixed << " float: " << static_cast<float> (ent_float) << 'f'
				<< std::endl;
			std::cout << std::fixed << " double: " << static_cast<double> (ent_float) <<  std::endl;			
					
				}
			}
			else
			{
				std::cout << " float: impossible " << std::endl;
				double ent_double;
				ss.clear();
				ss.seekg(0, std::ios::beg);
				ss >> ent_double;
				if (ss)
				{
					if (ent_double == std::floor(ent_double))
					{					
						std::cout << std::fixed << std::setprecision(1) << " double: " << static_cast<double> (ent_double) << std::endl;
						// std::cout << ent_double << std::endl;	
					}
					else {

				
				std::cout << std::fixed << " double: " << static_cast<double> (ent_double) <<  std::endl;			
					// std::cout << ent_double << std::endl;	
					}
				}
				else
					std::cout << " double: impossible " << std::endl;
			}
				
			
	} 
}

void ScalarConverter::convert( std::string const & entry )
{
	if (isSpecialCase(entry))	
		return specialCase(entry);	
	if (entry.find_first_of('.') != std::string::npos && *--entry.end() == 'f')
		floatCase(entry);		
	else if (entry.find_first_of('.') != std::string::npos)
		doubleCase(entry);	
	else if (entry.length() == 1 && !std::isdigit(*entry.c_str()))			
		charCase(entry);
	else	
		intCase(entry);	
}