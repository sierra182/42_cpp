/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 06:40:57 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 08:00:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cerrno>
#include <limits>
#include <cmath>
#include <algorithm>

class Parser
{	
	template <class T>
	void	flowHandle(T value, std::string const type)
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
	
	static bool	isNotSpace(const char c)
	{
		return !std::isspace(static_cast<unsigned char>(c));
	}

	long double	tryCastLongDouble( const std::string::iterator begin,
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
			flowHandle(valLdbl, "long double");					
		if (*endChar)
		{
			std::string rem = std::string(endChar);
			std::string::iterator it = std::find_if(rem.begin(), rem.end(),
				isNotSpace);
			if (it != rem.end())
			{
				std::cout << rem << std::endl;	
				throw std::invalid_argument("partial cast");
			}
		}
		return (valLdbl);
	}

	float	tryCastFloat(long double value)
	{
		if (std::isnan(value))
			throw std::invalid_argument("value is NaN");

		float valFlt = static_cast<float>(value);
		if (value != 0.0f)
			flowHandle(valFlt, "float");		
		return (valFlt);
	}

	int	tryCastInt(long double value)
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
	
	public :
	
		float	parseToFloat(const std::string::iterator begin, const std::string::iterator end)
		{		
			long double valLdbl = this->tryCastLongDouble(begin, end);
			float valFlt = this->tryCastFloat(valLdbl);
			
			return (valFlt);
		}	
};