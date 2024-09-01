/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:20:47 by seblin            #+#    #+#             */
/*   Updated: 2024/09/01 14:03:59 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser()
{
	return ;
}

Parser::~Parser()
{
	return ;
}

Parser::Parser(const Parser &)
{
	return ;
}
Parser & Parser::operator=(const Parser &)
{
	return (*this);
}

long double	Parser::tryCastLongDouble( const std::string::iterator begin,
	const std::string::iterator end)
{
	errno = 0;
	char * endChar;	
	long double valLdbl = 0.0;		
	
	std::string::iterator emp = std::find_if(begin, end, isNotSpace);
	if (emp == end)
		throw std::invalid_argument("empty value");
		
	std::string str_tmp = std::string(begin, end);
	const char * str_c = str_tmp.c_str();
	valLdbl = std::strtold(str_c, &endChar);
	if (errno == ERANGE)
		this->decimalFlowHandle(valLdbl, "long double");					
	if (*endChar)
	{
		std::string rem = std::string(endChar);
		std::string::iterator it = std::find_if(rem.begin(), rem.end(),
			this->isNotSpace);
		if (it != rem.end())	
			throw std::invalid_argument("bad input");		
	}
	return (valLdbl);
}

void	Parser::longFlowHandle(long value)
{		
	if (value == std::numeric_limits<long>::max())	
		throw std::overflow_error("Long: positive overflow");		
	else if (value == std::numeric_limits<long>::min())
		throw std::overflow_error("Long: negative overflow");			
}

long 	Parser::tryCastLong(const std::string::iterator begin,
	const std::string::iterator end)
{
	errno = 0;
	char * endChar;	
	long valL = 0.0;		
	
	std::string::iterator emp = std::find_if(begin, end, isNotSpace);
	if (emp == end)
		throw std::invalid_argument("empty value");
		
	std::string str_tmp = std::string(begin, end);
	const char * str_c = str_tmp.c_str();
	valL = std::strtol(str_c, &endChar, 10);
	if (errno == ERANGE)
		this->longFlowHandle(valL);						
	if (*endChar)
	{
		std::string rem = std::string(endChar);
		std::string::iterator it = std::find_if(rem.begin(), rem.end(),
			this->isNotSpace);
		if (it != rem.end())	
			throw std::invalid_argument("bad input");		
	}
	return (valL);
}

float	Parser::tryCastFloat(long double value)
{
	if (std::isnan(value))
		throw std::invalid_argument("value is NaN");

	float valFlt = static_cast<float>(value);
	if (value != 0.0f)
		this->decimalFlowHandle(valFlt, "float");		
	return (valFlt);
}

float	Parser::parseToFloat(const std::string::iterator begin,
	const std::string::iterator end)
{		
	long double valLdbl = this->tryCastLongDouble(begin, end);
	float valFlt = this->tryCastFloat(valLdbl);
	
	return (valFlt);
}

int	Parser::parseToInt(const std::string::iterator begin,
	const std::string::iterator end)
{		
	long valL = this->tryCastLong(begin, end);
	int valInt = this->tryCastInt(valL);
	
	return (valInt);
}

bool	Parser::isNotSpace(const char c)
{
	return !std::isspace(static_cast<unsigned char>(c));
}

bool	Parser::isSpace(const char c)
{
	return std::isspace(static_cast<unsigned char>(c));
}

void Parser::revTrim(std::string & str)
{
	std::string::reverse_iterator rit = std::find_if(str.rbegin(),
		str.rend(), this->isNotSpace);
	if (rit != str.rend())		
		str.erase(rit.base(), str.end());	
}