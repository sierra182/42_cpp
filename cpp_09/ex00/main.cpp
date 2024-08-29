/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/29 14:10:12 by svidot           ###   ########.fr       */
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

//!! ADD CONTS
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
	
	return parser.tryCastFloat(val_ldbl);
	// return true;
}

void	parseLine(std::string line, std::map<std::string, float> & input_map)
{
	
	std::string::iterator it = line.begin();
	float value = 0.0f;
	if (parseDate(line, it, 4, '-') && parseDate(line, it, 2, '-') && parseDate(line, it, 2, '|'))
	{
		value = parseValue(line, it);
		std::cout << "line parsed with succes: " << line << " v: " << value << std::endl;
		std::map<std::string, float>::iterator it = input_map.find(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));
		if (it == input_map.end())
			input_map.insert(make_pair(std::string(line.begin(), std::find(line.begin(), line.end(), '|')), value));
		else
			std::cout << "steel exist !!!!!!" << std::endl;	
	}
	else	
		std::cout << "holy shit: " << line <<  std::endl;
}

void addDataOnMap()
{
	
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
	while (std::getline(inf_inp, line))	
		if (!line.empty())		
			parseLine(line, input_map);		

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
				
	for (std::map<std::string, float>::iterator it = input_map.begin(); it != input_map.end(); it++)
		std::cout << "map: " << it->first << " : " << it->second << std::endl;

	std::cout << "****************" << std::endl;	
	for (std::map<std::string, float>::iterator it = data_map.begin(); it != data_map.end(); it++)
		std::cout << "data: " << it->first << " : " << it->second << std::endl;
	(void) argc, (void) argv;
	return (0);
}