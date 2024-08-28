/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/28 22:17:33 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include "MyStyl.hpp"
#include <sstream>
#include <map>
#include <cstdlib>
#include <limits>
#include <cmath>

bool parseDate(std::string & date, std::string::iterator & it,  int max, int delim)
{
	int nbr = 0;
	
	
	while (it != date.end() && *it != delim)
	{

		while (std::isspace(*it))
			it = date.erase(it);
		while (std::isdigit(*it))
		{std::cout << "digit: " << *it << std::endl;
			it++;
			nbr++; 
		}
		// while (std::isspace(*it))
		// 	it = date.erase(it);
		if (nbr > max)
			return std::cout << "too much digit" << std::endl, false;
		std::cout << "ici " << *it << std::endl;
		if (!std::isdigit(*it) && *it != delim && !std::isspace(*it))
			{ std::cout << "la" <<  *it << std::endl; std::cout << "not digit" << std::endl; return false;}		
		if (*it == delim && nbr == max)
			return it++, true;

	}
	return std::cout << "not enought" << std::endl, false;
}

long double	tryCastLongDouble(std::string::iterator & begin,
	std::string::iterator & end)
{
	errno = 0;
	char * end_char;	
	long double val_ldbl;
	
	val_ldbl = std::strtold(std::string(begin, end).c_str(),
		&end_char);				
	if (errno == ERANGE)
	{
		if (val_ldbl == 0.0L)
		{
			if (std::signbit(val_ldbl))
				std::cout << "negative underflow" << std::endl;
			else
				std::cout << "positive underflow" << std::endl;			
		}
		else if (std::isinf(val_ldbl))
		{
			if (val_ldbl < 0)
				std::cout << "negative overflow" << std::endl;
			else
				std::cout << "positive overflow" << std::endl;
		} 
	}
	if (*end_char)
		std::cout << "partial convertion" << std::endl;
	else
		std::cout << "succes" << std::endl;	
	return (val_ldbl);
}

float	tryCastFloat(long double value)
{
	float val_flt = static_cast<float>(value);
	
	if (val_flt == 0.0f)
	{
		if (std::signbit(val_flt))	
			std::cout << "negative underflow" << std::endl;
		else
			std::cout << "positive underflow" << std::endl;	
	}
	else if (std::isinf(val_flt))
	{			
		if (val_flt < 0)
			std::cout << "negative overflow" << std::endl;
		else
			std::cout << "positive overflow" << std::endl;		 
	}
	return (val_flt);
}

int	tryCastInt(long double value)
{
	long double trunc = static_cast<long double>(static_cast<int>(value));
	long double min = static_cast<long double>(std::numeric_limits<int>::min());
	long double max = static_cast<long double>(std::numeric_limits<int>::max());
	
	if (value < min	&& trunc != min)
		std::cout << "negative overflow" << std::endl;
	else if (value > max && trunc != max)
		std::cout << "positive overflow" << std::endl;
	return (static_cast<int>(value));
}

std::stringstream ss(std::string(it, value.end()));	
	float ss_flt;
	ss >> ss_flt;	
	if (ss && ss.eof())
		return std::cout << "the float is: " << ss_flt << std::endl, true;
	else 
		return std::cout << "the float is bad --> fuck you: " << ss_flt <<  std::endl, false;

void	parseLine(std::string line)
{
	std::map<std::string, float> input_map;
	std::string::iterator it = line.begin();
	if (parseDate(line, it, 4, '-') && parseDate(line, it, 2, '-') && parseDate(line, it, 2, '|') && parseValue(line, it))
	{
		std::cout << "line parsed with succes: " << line <<  std::endl;
		// input_map.insert(make_pair())
		// if 
		// line.substr(0, std::distance(line.begin(), it));
	}
	else	
		std::cout << "holy shit: " << line <<  std::endl;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
		return (MyStyl::error("we need one argument"), 1);
	errno = 0;
	std::ifstream inf(argv[1]);	
	if (inf.fail())	
		MyStyl::error(std::strerror(errno));
	
	std::string line;		
	while (std::getline(inf, line))
	{
		// std::cout << line << std::endl;
		parseLine(line);
		// return 0;
		// line.find()
		
	}	
		
	
	(void) argc, (void) argv;
	return (0);
}