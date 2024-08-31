/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 08:25:15 by seblin           ###   ########.fr       */
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
#include <ctime>

#include "Parser.hpp"

int searchIndex(std::map<std::string, float> map, std::string const & key)
{
	int i = 1;	
	std::map<std::string, float>::iterator it = map.begin();
	
	while (it != map.end() && it->first != key)
		it++, i++;
	return ++i;
}

void	isWrongDate(int year, int month, int day)
{
	struct tm date;
	std::memset(&date, 0, sizeof(date));
	
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	time_t time = std::mktime(&date);
	if (time == -1 || date.tm_year != year - 1900 || date.tm_mon != month - 1 || date.tm_mday != day)
		throw std::invalid_argument("wrong date");
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

void	parseLine(std::string & line, std::map<std::string, float> & inputMap)
{	
	Parser parser;
	std::string::iterator it = line.begin();
	float value = 0.0f;
	
	parseDate(line, it, 4, '-');	
	parseDate(line, it, 2, '-');
	parseDate(line, it, 2, '|');
	
	std::string::iterator tmpIt;
	std::string::iterator tmpIt2;
	
	tmpIt = std::find(line.begin() , line.end(), '-');
	std::cout << "one \e[45m" << std::string(line.begin(), tmpIt) <<  "\e[0m" << std::endl;
	int year = parser.parseToInt(line.begin(), tmpIt);
	std::cout << year << std::endl;
	
	tmpIt2 = std::find(++tmpIt , line.end(), '-');
	std::cout << "two \e[45m" <<  std::string(tmpIt, tmpIt2) << "\e[0m" <<  std::endl;
	int month = parser.parseToInt(tmpIt, tmpIt2);
	std::cout << month << std::endl;
	
	tmpIt = std::find(++tmpIt2 , line.end(), '|');
	std::cout << "three \e[45m" <<  std::string(tmpIt2, tmpIt) << "\e[0m" <<  std::endl;
	int day = parser.parseToInt(tmpIt2, tmpIt);
	std::cout << day << std::endl;

	isWrongDate(year, month, day);
	// std::string(line.begin(), std::find(line.begin() , line.end(), '-'));
	// std::string(line.begin(), std::find(line.begin() , line.end(), '|'));
	// std::cout << "HO \e[45m" << std::string(line.begin(), std::find(line.begin() , line.end(), '|')) << "\e[0m" <<  std::endl;
	// isWrongDate()	
	value = parser.parseToFloat(it, line.end());
	if (value < 0)		
		throw std::invalid_argument("Error: not a positive number.");		
	else if (value > 1000)
		throw std::invalid_argument("Error: too large a number.");
	inputMap[std::string(line.begin(), std::find(line.begin(), line.end(), '|'))] = value;	
}

int main(int argc, char * argv[])
{
	if (argc != 2)
		return (MyStyl::error("we need one argument"), 1);
	errno = 0;
	std::ifstream infInp(argv[1]);	
	if (infInp.fail())	
		return MyStyl::error(std::strerror(errno)), 1;
	errno = 0;
	std::ifstream infData("data.csv");	
	if (infData.fail())	
		return MyStyl::error(std::strerror(errno)), 1;
	
	std::map<std::string, float> inputMap;
	std::map<std::string, float> dataMap;
	Parser parser;
	std::string line;		
	bool first = true;		
	while (std::getline(infData, line))
	{				
		if (!line.empty())
		{
			if (!first)
			{				
				float value = parser.parseToFloat(++std::find(line.begin(), line.end(), ','), line.end()); 
				dataMap.insert(make_pair(std::string(line.begin(), std::find(line.begin(), line.end(), ',')),
				value));
			}
			else
				first = !first;
		}				
	}	
	//! wrong date
	first = false;
	int nLine = 1;	
	while (std::getline(infInp, line))
	{		
		try {		
			if (!line.empty() && (first = true))
			{
				std::cout << std::endl;
				std::cout << "\e[3;4mInput file:\e[0m  " << nLine <<
					" \e[31mline: " << "\e[37;45m" << line << "\e[0m"
					<< std::endl;

				std::map<std::string, float>::iterator itInp;
				std::map<std::string, float>::iterator itData;
				parseLine(line, inputMap);				
				
				itInp = inputMap.find(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));				
				itData = dataMap.lower_bound(std::string(line.begin(), std::find(line.begin(), line.end(), '|')));
							
				if (inputMap.end() != itInp && dataMap.end() != itData
					&& itInp->first == itData->first)				
					std::cout << "\e[32mthere is an exact entry\e[0m" << std::endl;				
				else if (itData == dataMap.begin())				
					std::cout << "\e[36mwe will take the first entry\e[0m" << std::endl;				
				else
				{
					std::cout << "\e[35mwe will take the previous entry\e[0m" << std::endl;
					itData--;
				}
											
				std::cout << "\e[3;4mData.csv:\e[0m  " << searchIndex(dataMap, itData->first) << " \e[31mline: " << "\e[37;46m" << itData->first << ',' << itData->second << "\e[0m" << std::endl;
				std::cout << "\e[31m " << itInp->second << " * " << itData->second << " => " << itInp->second * itData->second << " \e[0m" << std::endl;			
			}		
		}
		catch (std::exception const & e)
			{MyStyl::addWhat(e.what());}
		nLine++;	
	}
	if (!first)
		return (MyStyl::error("the file is empty"), 1);

	// for (std::map<std::string, float>::iterator it = ; it != )
			
	// for (std::map<std::string, float>::iterator it = inputMap.begin(); it != inputMap.end(); it++)
	// 	std::cout << "map: " << it->first << " : " << it->second << std::endl;

	// std::cout << "****************" << std::endl;	
	// for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); it++)
	// 	std::cout << "data: " << it->first << " : " << it->second << std::endl;
	(void) argc, (void) argv;
	std::cout << std::endl;
	return (0);
}