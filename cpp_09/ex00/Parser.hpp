/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 06:40:57 by seblin            #+#    #+#             */
/*   Updated: 2024/09/01 16:29:41 by svidot           ###   ########.fr       */
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
	void		flowHandle(T value, std::string const type) const;	
	long double	tryCastLongDouble( const std::string::iterator begin,
		const std::string::iterator end) const;	
	float		tryCastFloat(long double value) const;
	int			tryCastInt(long double value) const;
	
	public :
		
		Parser();
		~Parser();
		float		parseToFloat(const std::string::iterator begin,
			const std::string::iterator end) const;
		static bool	isNotSpace(const char c);
		static bool	isSpace(const char c);
		void 		revTrim(std::string & str) const;		
};

template <class T>
void	Parser::flowHandle(T value, std::string const type) const
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