/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:19 by seblin            #+#    #+#             */
/*   Updated: 2024/08/03 17:53:35 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>

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

void ScalarConverter::floatCase( std::string entry )
{
	std::stringstream	ss(entry);
	float				ent_float;
	
	ss >> ent_float;
	if (ss)
	{	std::cout << "[FLOAT] :" << ent_float <<std::endl;
	
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
			
		std::string suff = ".0";		
		if (ent_float - static_cast<int>(ent_float)) 
			suff = "";			
		std::cout << " float: " << static_cast<float> (ent_float) << suff + 'f'
			<< std::endl;
		std::cout << " double: " << static_cast<double> (ent_float) << suff
			<< std::endl;			
	}	
	else displayAllImpossible();
}	

void ScalarConverter::doubleCase( std::string entry )
{
	std::stringstream	ss(entry);
	double				ent_double;
	
	ss >> ent_double;
	if (ss)
	{	std::cout << "[DOUBL] :" <<std::endl;
	
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
		if (ent_double - static_cast<int>(ent_double)) 
			suff = "";
		std::cout << " float: " << static_cast<float> (ent_double)
			<< suff + 'f' << std::endl;
		std::cout << " double: " << static_cast<double> (ent_double) << suff
			<< std::endl;	
	}
	else displayAllImpossible();	
}

void ScalarConverter::charCase( std::string entry )
{
	std::stringstream	ss(entry);
	char				ent_char;

	ss >> ent_char;
	if (ss)
	{	std::cout << "[CHAR] :" <<std::endl;		
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
	{	std::cout << "[INT] :" <<std::endl;

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
	else displayAllImpossible();
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