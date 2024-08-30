/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/30 20:28:32 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include "MyStyl.hpp"
#include <sstream>
#include <map>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cmath>

#include "Parser.hpp"

int searchIndex(std::map<std::string, float> map, std::string const & key)
{
	int i = 1;	
	std::map<std::string, float>::iterator it = map.begin();
	
	while (it != map.end() && it->first != key)
		it++, i++;
	return ++i;
}

bool parseDate(std::string & date, std::string::iterator & it,
	 int max, int delim)
{
	int nbr = 0;
			
	while (it != date.end() && *it != delim)
	{
		while (std::isspace(*it))
			it = date.erase(it);
		while (std::isdigit(*it))		
			it++, nbr++; 	
		if (nbr > max)
			throw std::invalid_argument("too much digit");		
		if (!std::isdigit(*it) && *it != delim && !std::isspace(*it))
			throw std::invalid_argument("bad input");				
		if (*it == delim && nbr == max)
			return it++, true;
	}
	throw std::invalid_argument("not enought digit");	
}

float	parseValue( std::string & value, const std::string::iterator it)
{
	Parser parser;
	long double val_ldbl = parser.tryCastLongDouble(it, value.end());	
	return  parser.tryCastFloat(val_ldbl);
}
//!gerer les exception float et long double
void	parseLine(std::string & line, std::map<std::string, float> & input_map)
{	
	std::string::iterator it = line.begin();
	float value = 0.0f;
	parseDate(line, it, 4, '-');
	parseDate(line, it, 2, '-');
	parseDate(line, it, 2, '|');
	
	// if (parseDate(line, it, 4, '-') && parseDate(line, it, 2, '-') && parseDate(line, it, 2, '|'))
	// {
		// std::cout << "\e[3;4mInput file:\e[0m  " << n_line << " \e[31mline: " << "\e[37;45m" << line << "\e[0m" << std::endl;
		value = parseValue(line, it);
		if (value < 0)		
			throw std::invalid_argument("Error: not a positive number.");		
		else if (value > 1000)
			throw std::invalid_argument("Error: too large a number.");
		input_map[std::string(line.begin(), std::find(line.begin(), line.end(), '|'))] = value;			
	// }
}

int main(int argc, char * argv[])
{
	if (argc != 2)
		return (MyStyl::error("we need one argument"), 1);
	errno = 0;
	std::ifstream inf_inp(argv[1]);	
	if (inf_inp.fail())	
		return MyStyl::error(std::strerror(errno)), 1;
	errno = 0;
	std::ifstream inf_data("data.csv");	
	if (inf_data.fail())	
		return MyStyl::error(std::strerror(errno)), 1;
	
	std::map<std::string, float> input_map;
	std::map<std::string, float> data_map;

	std::string line;		
	bool first = true;		
	while (std::getline(inf_data, line))
	{				
		if (!line.empty())
		{
			if (!first)
			{				
				float value = parseValue(line, ++std::find(line.begin(), line.end(), ','));
				data_map.insert(make_pair(std::string(line.begin(), std::find(line.begin(), line.end(), ',')),
				value));
			}
			else
				first = !first;
		}				
	}	
	//! wrong date
	first = false;
	int n_line = 1;	
	while (std::getline(inf_inp, line))
	{		
		try {		
			if (!line.empty() && (first = true))
			{
				std::cout << std::endl;
				std::cout << "\e[3;4mInput file:\e[0m  " << n_line << " \e[31mline: " << "\e[37;45m" << line << "\e[0m" << std::endl;

				std::map<std::string, float>::iterator it_inp;
				std::map<std::string, float>::iterator it_data;
				parseLine(line, input_map);	
			
				
				it_inp = input_map.find(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));				
				it_data = data_map.lower_bound(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));
							
				if (input_map.end() != it_inp && data_map.end() != it_data
					&& it_inp->first == it_data->first)				
					std::cout << "\e[32mthere is an exact entry\e[0m" << std::endl;				
				else if (it_data == data_map.begin())				
					std::cout << "\e[36mwe will take the first entry\e[0m" << std::endl;				
				else
				{
					std::cout << "\e[35mwe will take the previous entry\e[0m" << std::endl;
					it_data--;
				}
											
				std::cout << "\e[3;4mData.csv:\e[0m  " << searchIndex(data_map, it_data->first) << " \e[31mline: " << "\e[37;46m" << it_data->first << ',' << it_data->second << "\e[0m" << std::endl;
				std::cout << "\e[31m " << it_inp->second << " * " << it_data->second << " => " << it_inp->second * it_data->second << " \e[0m" << std::endl;			
			}		
		}
		catch (std::exception const & e)
			{MyStyl::addWhat(e.what());}
		n_line++;	
	}
	if (!first)
		return (MyStyl::error("the file is empty"), 1);

	// for (std::map<std::string, float>::iterator it = ; it != )
			
	// for (std::map<std::string, float>::iterator it = input_map.begin(); it != input_map.end(); it++)
	// 	std::cout << "map: " << it->first << " : " << it->second << std::endl;

	// std::cout << "****************" << std::endl;	
	// for (std::map<std::string, float>::iterator it = data_map.begin(); it != data_map.end(); it++)
	// 	std::cout << "data: " << it->first << " : " << it->second << std::endl;
	(void) argc, (void) argv;
	std::cout << std::endl;
	return (0);
}