/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/29 21:27:40 by seblin           ###   ########.fr       */
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
//!! ADD CONTS
bool parseDate(std::string & date, std::string::iterator & it,  int max, int delim, int n_line)
{
	int nbr = 0;
		
	while (it != date.end() && *it != delim)
	{
		while (std::isspace(*it))
			it = date.erase(it);
		while (std::isdigit(*it))
		{
			it++;
			nbr++; 
		}
		if (nbr > max)
			return std::cout << "too much digit: index: " << n_line << ", " << date << std::endl, false;		
		if (!std::isdigit(*it) && *it != delim && !std::isspace(*it))
			{ std::cout << "bad input: index: " << n_line << " : " << date << std::endl; return false;}		
		if (*it == delim && nbr == max)
			return it++, true;

	}
	return std::cout << "not enought digit: index: " << n_line << " : " << date << std::endl, false;
}



// std::stringstream ss(std::string(it, value.end()));	
// 	float ss_flt;
// 	ss >> ss_flt;	
// 	if (ss && ss.eof())
// 		return std::cout << "the float is: " << ss_flt << std::endl, true;
// 	else 
// 		return std::cout << "the float is bad --> fuck you: " << ss_flt <<  std::endl, false;

float	parseValue( std::string & value, const std::string::iterator it)
{
	Parser parser;
	long double val_ldbl = parser.tryCastLongDouble(it, value.end());
	// std::cout << parser.tryCastFloat(val_ldbl) << std::endl;
	// std::cout << parser.tryCastInt(val_ldbl) << std::endl;
	
	return  parser.tryCastFloat(val_ldbl);
	// return true;
}
//!gerer les exception float et long double
void	parseLine(std::string line, std::map<std::string, float> & input_map, int n_line)
{
	
	std::string::iterator it = line.begin();
	float value = 0.0f;
	if (parseDate(line, it, 4, '-', n_line) && parseDate(line, it, 2, '-', n_line) && parseDate(line, it, 2, '|', n_line))
	{
		std::cout << "\e[3;4mInput file:\e[0m  " << n_line << " \e[31mline: " << "\e[37;45m" << line << "\e[0m" << std::endl;
		value = parseValue(line, it);
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			return;
		}
		else if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;	
			return;	
		}
		std::map<std::string, float>::iterator it = input_map.find(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));
		if (it == input_map.end())		
			input_map.insert(make_pair(std::string(line.begin(), std::find(line.begin(), line.end(), '|')), value));		
		else
			std::cout << "Error: the entry yet exist." << std::endl;	
	}
	// else	
	// 	std::cout << "holy shit: " << line <<  std::endl;
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
	//!num of ligne 
		//!test with empty file (or with only space)
	first = false;
	int n_line = 1;	
	while (std::getline(inf_inp, line))	
		if (!line.empty() && (first = true))
		{
			std::cout << std::endl;
			std::map<std::string, float>::iterator it_inp;
			std::map<std::string, float>::iterator it_data;
			parseLine(line, input_map, n_line);	
			// std::cout << "YOUPI " << std::string(line.begin(), std::find(line.begin(), line.end(), '|')) << std::endl;	
			
			it_inp = input_map.find(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));
			
			it_data = data_map.lower_bound(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));
			// if (it_data == data_map.end())
				// std::cout << "c la end!" << std::endl;
			if (it_data != data_map.end() && it_inp->first == it_data->first)
			{
				std::cout << "\e[32mthere is an exact entry\e[0m" << std::endl;
			}
			else if (it_data == data_map.end() || (it_inp->first != it_data->first && data_map.begin() != it_data))
			{
				std::cout << "\e[35mwe will take the previous entry\e[0m" << std::endl;
				it_data--;
			}
			else
			{
				std::cout << "\e[36mwe will take the first entry\e[0m" << std::endl;
			}
				
				// else if (it_data == data_map.end())
				// {
					
				// }	
			
			// else if (it_inp->first != it_data->first && input_map.end() == it_data)
			// {
			// 	it_data = input_map
			// }//?
			std::cout << "\e[3;4mData.csv:\e[0m  " << searchIndex(data_map, it_data->first) << " \e[31mline: " << "\e[37;46m" << it_data->first << ',' << it_data->second << "\e[0m" << std::endl;
			// std::cout << searchIndex(data_map, it_data->first) << "\e[31m The place is \e[0m" << it_data->first << " " << it_data->second << std::endl;
			// std::cout << "\e[31mat the index \e[0m" << searchIndex(data_map, it_data->first) << std::endl;
			std::cout << "\e[31m " << it_inp->second << " * " << it_data->second << " => " << it_inp->second * it_data->second << " \e[0m" << std::endl;
			// else 
			// 	std::cout << "not find" << std::endl;
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