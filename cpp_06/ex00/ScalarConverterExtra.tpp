/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterExtra.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:59:25 by seblin            #+#    #+#             */
/*   Updated: 2024/08/26 11:23:29 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>

template<class T, class U>
void ScalarConverter::decimalHandle(T entry, std::string flt)
{
	std::string suff;			
	if  ((	std::fabs(static_cast<U> (entry))
			== std::floor(std::fabs(static_cast<U> (entry)))
			&&
			std::fabs(static_cast<U> (entry)) >= 1e-4
			&& std::fabs(static_cast<U> (entry)) < 1e+8)		
			|| entry == 0.0)
	{		
		suff = ".0";				
	}
	if (flt.empty())
		std::cout << " double: " << static_cast<U> (entry) << suff
			<< std::endl;
	else
		std::cout << " float: " << static_cast<U> (entry) << suff
			+ 'f' << std::endl;
}

template <class T>
void ScalarConverter::charHandle(T entry)
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
void ScalarConverter::intHandle(T entry)
{
	if (static_cast<long int>(entry) <= std::numeric_limits<int>::max()
		&& static_cast<long int>(entry) >= std::numeric_limits<int>::min())
		std::cout << " int: " << static_cast<int> (entry) << std::endl;
	else
		std::cout << " int: impossible " << std::endl;
}
