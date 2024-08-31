/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:20:47 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 16:27:23 by seblin           ###   ########.fr       */
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
		this->flowHandle(valLdbl, "long double");					
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

float	Parser::tryCastFloat(long double value)
{
	if (std::isnan(value))
		throw std::invalid_argument("value is NaN");

	float valFlt = static_cast<float>(value);
	if (value != 0.0f)
		this->flowHandle(valFlt, "float");		
	return (valFlt);
}

int	Parser::tryCastInt(long double value)
{
	if (std::isnan(value))
		throw std::invalid_argument("value is NaN");

	long double min = static_cast<long double>
		(std::numeric_limits<int>::min());
	long double max = static_cast<long double>
		(std::numeric_limits<int>::max());
	
	if (value < min)
		throw std::overflow_error("int negative overflow");
	else if (value > max)
		throw std::overflow_error("int positive overflow");			
	return (static_cast<int>(value));
}

float	Parser::parseToFloat(const std::string::iterator begin,
	const std::string::iterator end)
{		
	long double valLdbl = this->tryCastLongDouble(begin, end);
	float valFlt = this->tryCastFloat(valLdbl);
	
	return (valFlt);
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