/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterExtra.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:59:25 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 17:53:31 by seblin           ###   ########.fr       */
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
#include <iomanip>

bool ScalarConverter::isSpecialCase( std::string entry )
{
	return (entry == "inf" || entry == "inff"
		|| entry == "+inf" || entry == "+inff"
		|| entry == "-inff" || entry == "-inf"
		|| entry == "nan" || entry == "nanf");
}

void ScalarConverter::specialCase( std::string const & entry )
{
	std::cout << "\e[1m 👽...you entered a special case...👻 \e[0m" 
		<< std::endl << std::endl;
			
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
	std::cout << "\e[1m 🥶...you entered an invalid input...🤯 \e[0m" 
		<< std::endl << std::endl;
		
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
	{
		std::cout << "\e[1;32m you entered a float \e[0;35m"
			<< ent_float << std::endl <<std::endl;	
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
			
		std::string suff;		
		if ((std::fabs(ent_float) == std::floor(std::fabs(ent_float))
			&& std::fabs(ent_float) >= 1e-6 && std::fabs(ent_float) < 1e+8)
			|| !ent_float)
			suff = ".0";
		std::cout << " float: " << static_cast<float> (ent_float)
			<< suff + 'f' << std::endl;
		std::cout << " double: " << static_cast<double> (ent_float) << suff
			<< std::endl;		
	}	
	else 		
		displayAllImpossible(); 	
}	

void ScalarConverter::doubleCase( std::string entry )
{
	std::stringstream	ss(entry);
	double				ent_double;
	
	ss >> ent_double;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered a double \e[0;34m" 
			<< ent_double << std::endl << std::endl;	
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

		std::string suff;		
		if ((std::fabs(ent_double) == std::floor(std::fabs(ent_double))
			&& std::fabs(ent_double) >= 1e-6 && std::fabs(ent_double) < 1e+8)
			|| !ent_double)
			suff = ".0";
		std::cout << " float: " << static_cast<float> (ent_double)
			<< suff + 'f' << std::endl;
		std::cout << " double: " << static_cast<double> (ent_double) << suff
			<< std::endl;	
	}
	else 		
		displayAllImpossible();	
}

void ScalarConverter::charCase( std::string entry )
{
	std::stringstream	ss(entry);
	char				ent_char;

	ss >> ent_char;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered a char \e[0;33m"
			<< ent_char << std::endl <<std::endl;		
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
	else 		
		displayAllImpossible();
}

void ScalarConverter::intCase( std::string entry )
{
	std::stringstream	ss(entry);
	int					ent_int;

	ss >> ent_int;
	if (ss)
	{	
		std::cout << "\e[1;32m you entered an int \e[0;31m" 
			<< ent_int << std::endl << std::endl;
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
				
		std::string suff;		
		if ((std::fabs(ent_int) >= 1e-6 && std::fabs(ent_int) < 1e+8)
			|| !ent_int)
			suff = ".0";
		std::cout << " float: " << static_cast<float> (ent_int)
			<< suff + 'f' << std::endl;
		std::cout << " double: " << static_cast<double> (ent_int) << suff
			<< std::endl;
	}	
	else 		
		displayAllImpossible();
}

void ScalarConverter::convert( std::string const & entry )
{
	std::cout << std::setprecision(8) <<std::endl;
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