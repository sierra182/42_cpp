/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterExtra.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:59:25 by seblin            #+#    #+#             */
/*   Updated: 2024/08/26 10:28:15 by seblin           ###   ########.fr       */
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

template<class T, class U>
void decimalHandle(T entry, std::string flt = "")
{
	std::string suff;		
	if  ((	std::fabs(static_cast<U> (entry)) == std::floor(std::fabs(static_cast<U> (entry)))
			&&
			std::fabs(static_cast<U> (entry)) >= 1e-4 && std::fabs(static_cast<U> (entry)) < 1e+8)		
			|| entry == 0.0)
	{		
		suff = ".0";				
	}
	if (flt.empty())
		std::cout << " double: " << static_cast<U> (entry) << suff << std::endl;
	else
		std::cout << " float: " << static_cast<U> (entry) << suff + 'f' << std::endl;
}

template <class T>
void addDFloatSuff(T entry)
{
	// std::cout << " YE " << std::floor(std::fabs(static_cast<float> (entry))) << std::endl;
	// std::cout << " YO "<< std::fabs(static_cast<float> (entry)) << std::endl;
	
	// std::string suff;		
	// if  (		
	// 		(std::fabs(static_cast<float> (entry)) == std::floor(std::fabs(static_cast<float> (entry)))
	// 		&&
	// 		std::fabs(static_cast<float> (entry)) >= 1e-4 && std::fabs(static_cast<float> (entry)) < 1e+8)		
	// 	|| entry == 0.0)
	// {		
	// 	suff = ".0";				
	// }
	// std::cout << " float: " << static_cast<float> (entry) << suff + 'f' << std::endl;
	// suff = "";
	
	// if  (		
	// 		(std::fabs(static_cast<double> (entry)) == std::floor(std::fabs(static_cast<double> (entry)))
	// 		&&
	// 		std::fabs(static_cast<double> (entry)) >= 1e-4 && std::fabs(static_cast<double> (entry)) < 1e+8)		
	// 	|| entry == 0.0)
	// {		
	// 	suff = ".0";				
	// }
	// std::cout << " double: " << static_cast<double> (entry) << suff << std::endl;
}

template <class T>
void charHandle(T entry)
{
	if (entry >= 0 && entry <= 127)
	{
		if (std::isprint(static_cast<int>(entry)))			
			std::cout << " char : '" << static_cast<char> (entry)
				<< '\'' << std::endl;
		else
			std::cout << " char : Non displayable" << std::endl;			
	}
	else			
		std::cout << " char : impossible" << std::endl;
}

template <class T>
void intHandle(T entry)
{
	if (static_cast<int>(entry) <= std::numeric_limits<int>::max()
		&& static_cast<int>(entry) >= std::numeric_limits<int>::min())
		std::cout << " int: " << static_cast<int> (entry) << std::endl;
	else
		std::cout << " int: impossible " << std::endl;
}

void ScalarConverter::floatCase( std::string entry )
{
	std::stringstream	ss(entry);
	float				ent_float;
	
	ss >> ent_float; 
	std::string sequel;
	ss >> sequel;
	
	if (ss && (sequel == "f" || sequel == ".f"))
	{
		std::cout << "\e[1;32m you entered a float \e[0;35m"
			<< ent_float << std::endl <<std::endl;	
		charHandle(ent_float);
		// if (ent_float >= 0 && ent_float <= 127)
		// {
		// 	if (std::isprint(static_cast<int>(ent_float)))			
		// 		std::cout << " char : '" << static_cast<char> (ent_float)
		// 			<< '\'' << std::endl;
		// 	else
		// 		std::cout << " char : Non displayable" << std::endl;			
		// }
		// else			
		// 	std::cout << " char : impossible" << std::endl;
		intHandle(ent_float);	
		// if (ent_float <= static_cast<float>(std::numeric_limits<int>::max())
		// 	&& ent_float >= static_cast<float>(std::numeric_limits<int>::min()))
		// 	std::cout << " int: " << static_cast<int> (ent_float) << std::endl;
		// else
		// 	std::cout << " int: impossible " << std::endl;
		// addDFloatSuff(ent_float);	
		decimalHandle<float, float>(ent_float, "flt");
		decimalHandle<float, double>(ent_float);
		
	}	
	else 		
		displayAllImpossible(); 	
}	



void ScalarConverter::doubleCase( std::string entry )
{
	std::stringstream	ss(entry);
	double				ent_double;
	
	ss >> ent_double;

	if (ss && ss.eof())
	{	
		std::cout << "\e[1;32m you entered a double \e[0;34m" 
			<< ent_double << std::endl << std::endl;
		charHandle(ent_double);	
		// if (ent_double >= 0 && ent_double <= 127)
		// {
		// 	if (std::isprint(static_cast<int>(ent_double)))			
		// 		std::cout << " char : '" << static_cast<char> (ent_double)
		// 			<< '\'' << std::endl;
		// 	else
		// 		std::cout << " char : Non displayable" << std::endl;
		// }
		// else			
		// 	std::cout << " char : impossible" << std::endl;
		intHandle(ent_double);
		// if (ent_double <= static_cast<double>(std::numeric_limits<int>::max())
		// 	&& ent_double >= std::numeric_limits<int>::min())
		// 	std::cout << " int: " << static_cast<int> (ent_double)
		// 		<< std::endl;
		// else
		// 	std::cout << " int: impossible " << std::endl;
		// addDFloatSuff(ent_double);	
		decimalHandle<double, float>(ent_double, "flt");
		decimalHandle<double, double>(ent_double);
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
		charHandle(ent_char);		
		// if (std::isprint(ent_char))			
		// 	std::cout << " char : '" << static_cast<char> (ent_char) <<
		// 	'\'' << std::endl;
		// else
		// 	std::cout << " char : Non displayable" << std::endl;	
		intHandle(ent_char);
		
		// std::cout << " int: " << static_cast<int> (ent_char) << std::endl;
		// addDFloatSuff(ent_char);
		decimalHandle<char, float>(ent_char, "flt");
		decimalHandle<char, double>(ent_char);
		// std::cout << " float: " << static_cast<float> (ent_char) << ".0f" 
		// 	<< std::endl;
		// std::cout << " double: " << static_cast<double> (ent_char) << ".0"
		// 	<< std::endl;		
	}
	else 		
		displayAllImpossible();
}

void ScalarConverter::intCase( std::string entry )
{
	std::stringstream	ss(entry);
	int					ent_int;

	ss >> ent_int;
	if (ss && ss.eof())
	{	
		std::cout << "\e[1;32m you entered an int \e[0;31m" 
			<< ent_int << std::endl << std::endl;
		charHandle(ent_int);
		// if (ent_int >= 0 && ent_int <= 127)
		// {
		// 	if (std::isprint(ent_int))			
		// 		std::cout << " char : '" << static_cast<char> (ent_int) <<
		// 			'\'' << std::endl;
		// 	else
		// 		std::cout << " char : Non displayable" << std::endl;
		// }
		// else			
		// 	std::cout << " char : impossible" << std::endl;
		intHandle(ent_int);
		// if (ent_int <= std::numeric_limits<int>::max()
		// 	&& ent_int >= std::numeric_limits<int>::min())
		// 		std::cout << " int: " << static_cast<int> (ent_int)
		// 			<< std::endl;
		// 	else
		// 		std::cout << " int: impossible " << std::endl;
		// addDFloatSuff(ent_int);	
		decimalHandle<int, float>(ent_int, "flt");
		decimalHandle<int, double>(ent_int);		
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