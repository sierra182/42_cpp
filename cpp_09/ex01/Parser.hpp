/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 06:40:57 by seblin            #+#    #+#             */
/*   Updated: 2024/09/01 13:39:32 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cerrno>
#include <limits>
#include <cmath>
#include <algorithm>

class Parser
{	
	Parser(const Parser &);
	Parser & operator=(const Parser &);
	
	template <class T>
	void		decimalFlowHandle(T value, std::string const type);
	void		longFlowHandle(long value);
	long double	tryCastLongDouble( const std::string::iterator begin,
		const std::string::iterator end);	
	float		tryCastFloat(long double value);
	template <class T>
	int			tryCastInt(T value);
	long 		tryCastLong(const std::string::iterator begin,
		const std::string::iterator end);
	
	public :
		
		Parser();
		~Parser();
		float		parseToFloat(const std::string::iterator begin,
			const std::string::iterator end);
		int			parseToInt(const std::string::iterator begin,
			const std::string::iterator end);
		static bool	isNotSpace(const char c);
		static bool	isSpace(const char c);
		void 		revTrim(std::string & str);		
};

template <class T>
void	Parser::decimalFlowHandle(T value, std::string const type)
{		
	if (std::isinf(value))
	{
		if (value < 0.0)
			throw std::overflow_error(type + ": negative overflow");
		else
			throw std::overflow_error(type + ": positive overflow");
	} 	
	else if (value == 0.0)
	{
		if (std::signbit(value))
			throw std::underflow_error(type + ": negative underflow");
		else
			throw std::underflow_error(type + ": positive underflow");			
	}		
}

template <class T>
int	Parser::tryCastInt(T value)
{
	if (std::isnan(value))
		throw std::invalid_argument("value is NaN");

	T min = static_cast<T>(std::numeric_limits<int>::min());
	T max = static_cast<T>(std::numeric_limits<int>::max());
	
	if (value < min)
		throw std::overflow_error("int negative overflow");
	else if (value > max)
		throw std::overflow_error("int positive overflow");			
	return (static_cast<int>(value));
}