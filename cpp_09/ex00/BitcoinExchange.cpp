/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:18:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 22:48:50 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "MySty.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <ctime>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>

BitcoinExchange::BitcoinExchange( void ){}

BitcoinExchange::~BitcoinExchange( void ){}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}
BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange & )
{
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::ifstream & infData,
	std::ifstream & infInp)
{
	this->fillDataMap(infData);	
	this->fillInputMap(infInp);		
}

int BitcoinExchange::searchIndex(std::map<std::string, float> map,
	std::string const & key)
{
	int i = 1;	
	std::map<std::string, float>::iterator it = map.begin();
	
	while (it != map.end() && it->first != key)
		it++, i++;
	return ++i;
}

void	BitcoinExchange::isWrongDate(int year, int month, int day)
{
	struct tm date;
	std::memset(&date, 0, sizeof(date));
	
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	time_t time = std::mktime(&date);
	if (time == -1 || date.tm_year != year - 1900
		|| date.tm_mon != month - 1 || date.tm_mday != day)
		throw std::invalid_argument("wrong date");
}

void	BitcoinExchange::checkDate(std::string & line)
{
	std::string::iterator tmpIt;
	std::string::iterator tmpIt2;
	
	tmpIt = std::find(line.begin() , line.end(), '-');
	int year = std::atoi(std::string(line.begin(), tmpIt).c_str());	
	tmpIt2 = std::find(++tmpIt , line.end(), '-');
	int month = std::atoi(std::string(tmpIt, tmpIt2).c_str());	
	tmpIt = std::find(++tmpIt2 , line.end(), '|');
	int day = std::atoi(std::string(tmpIt2, tmpIt).c_str());;

	this->isWrongDate(year, month, day);	
}

bool	BitcoinExchange::parseDate(std::string & date,
	std::string::iterator & it, int max, int delim)
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

void	BitcoinExchange::parseLine(std::string & line, std::map<std::string,
	float> & inputMap, char sep)
{	
	Parser parser;
	std::string::iterator it = line.begin();
	float value = 0.0f;
	
	this->parseDate(line, it, 4, '-');	
	this->parseDate(line, it, 2, '-');
	this->parseDate(line, it, 2, sep);	
	this->checkDate(line);	
	value = parser.parseToFloat(it, line.end());
	if (sep == '|')
	{		
		if (value < 0)		
			throw std::invalid_argument("Error: not a positive number.");		
		else if (value > 1000)
			throw std::invalid_argument("Error: too large a number.");
	}
	inputMap[std::string(line.begin(),
		std::find(line.begin(), line.end(), sep))] = value;	
}

void BitcoinExchange::colorFullLine(const std::string & str,
	short unsigned int color)
{
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	std::string empty(static_cast<int>(ws.ws_col * .75f), ' ');
	std::cout << "\e[4" << color << "m" << empty << "\r" << str << "\e[0m";
}
void	BitcoinExchange::printRslt(const std::map<std::string,
	float>::const_iterator itInp, const std::map<std::string,
	float>::const_iterator itData, short unsigned int colorArr[],
	short unsigned int color)
{
	// colorFullLine("\e[32mteste moi le cul", 5);
	// colorFullLine("\e[32mteste moi le cul", 5);
	// std::string dep;
	// std::string inpStr = dep + "\e[3;4mData.csv:\e[0m  " + 
	// this->searchIndex(dataMap, itData->first) + " \e[31mline: " +
	//  "\e[37;46m" + itData->first + ',' + itData->second + "\e[0m";

	std::ostringstream oss;
	oss << "\e[3;4;4" << colorArr[color] << "m" << "mData.csv:\e[0m" << "\e[4" << colorArr[color] <<  "m " <<
		this->searchIndex(dataMap, itData->first) << " \e[31mline: "
			<< "\e[37;4;4";
	color = static_cast<unsigned short int>(((static_cast<unsigned int>(color)) + 1) % 2);
			oss << colorArr[color] << "m" << itData->first << ',' << itData->second
			<< "\e[0m" << std::endl;
	color = static_cast<unsigned short int>(((static_cast<unsigned int>(color)) + 1) % 2);
	MySty::colorFullLine(oss.str(), colorArr[color]);
	oss.str("");
		
	oss << "\e[3;4;4" << colorArr[color] << "m\e[31m " << itInp->second << " * " << itData->second <<
		" => " << itInp->second * itData->second << " \e[0m" << std::endl;
	MySty::colorFullLine(oss.str(), colorArr[color]);
}

void	BitcoinExchange::makeExchange(std::string const & line,
	short unsigned int colorArr[], short unsigned int color)
{
	std::map<std::string, float>::iterator itInp;
	std::map<std::string, float>::iterator itData;
	std::ostringstream oss; 
	itInp = inputMap.find(std::string(line.begin(),
		std::find(line.begin(), line.end(), '|')));				
	itData = dataMap.lower_bound(std::string(line.begin(),
		std::find(line.begin(), line.end(), '|')));
	oss << "\e[4" << color << "m";			
	if (inputMap.end() != itInp && dataMap.end() != itData
		&& itInp->first == itData->first)				
		oss << "\e[32mthere is an exact entry\e[0m" << std::endl;				
	else if (itData == dataMap.begin())				
		oss << "\e[36mwe will take the first entry\e[0m" << std::endl;				
	else
	{
		oss << "\e[35mwe will take the previous entry\e[0m" << std::endl;
		itData--;
	}
	MySty::colorFullLine(oss.str(), colorArr[color]);
	this->printRslt(itInp, itData, colorArr, color);
}

bool	BitcoinExchange::isFirstLineValid(std::string line, Parser & parser,
	std::string const & comp1, char const comp2, std::string const & comp3)
{
	std::istringstream ss(line);
			 
	if (std::getline(ss >> std::ws, line, comp2))
	{
		parser.revTrim(line);	
		if (line == comp1)
		{
			if (std::getline(ss >> std::ws, line))
			{
				parser.revTrim(line);
				if (line == comp3)
					return true;
			}
		}
	}
	return false;
}

void	BitcoinExchange::fillDataMap(std::ifstream & infData)
{
	std::string::iterator it;
	std::string line;
	Parser parser;
	bool first = true;
	int nLine = 1;
	
	std::string tmpTime;
	while (std::getline(infData, line))
	{		
		try {
			it = std::find_if(line.begin(), line.end(),	parser.isNotSpace);		
			if ((!line.empty() && it != line.end()))
			{
				if ((!isFirstLineValid(line, parser, "date", ',',
					"exchange_rate") && first) || !first)
				{	
					first = false;
					std::string tmpLine = line;
					this->parseLine(line, this->dataMap, ',');
					std::map<std::string, float>::iterator itOrder;	
					itOrder = this->dataMap.find(std::string(tmpLine.begin(),
					std::find(tmpLine.begin(), tmpLine.end(), ',')));				
					if (itOrder->first < tmpTime)
						throw std::invalid_argument("data are disordered");
					else if (itOrder->first == tmpTime)
						throw std::invalid_argument("data are double");
					else
						tmpTime = itOrder->first;
				}
				else
					first = false;
			}
		}
		catch (std::exception const & e)
		{	
			std::cout << std::endl;
			std::cout << "\e[3;4mData file:\e[0m  " << nLine <<
				" \e[31mline: " << "\e[37;45m" << line << "\e[0m"
				<< std::endl;		
			throw;
		}
		nLine++;	
	}	
	if (first)
		throw std::invalid_argument("the data file is empty");
}

void	BitcoinExchange::fillInputMap(std::ifstream & infInp)
{
	std::string::iterator it;
	std::string line;
	Parser parser;
	bool first = true;
	int nLine = 1;
	short unsigned int color = 0;
	short unsigned int colorArr[] = {5, 6};
	while (std::getline(infInp, line))
	{		
		try {
			it = std::find_if(line.begin(), line.end(),	parser.isNotSpace);		
			if ((!line.empty() && it != line.end()))
			{
				if ((!isFirstLineValid(line, parser, "date", '|', "value")
					&& first) || !first)
				{	
					first = false;				
					// std::cout << std::endl;
					color = static_cast<unsigned short int>(((static_cast<unsigned int>(color)) + 1) % 2);		
					std::ostringstream oss;
					oss << "\e[3;4" << colorArr[color] << "mInput file:  " << nLine;
					color = static_cast<unsigned short int>(((static_cast<unsigned int>(color)) + 1) % 2);
					oss <<	" \e[31mline: " << "\e[37;4" << colorArr[color] << "m" <<
						 line << "\e[0m"
						<< std::endl;
					color = static_cast<unsigned short int>(((static_cast<unsigned int>(color)) + 1) % 2);
					MySty::colorFullLine(oss.str(), colorArr[color]);
					this->parseLine(line, this->inputMap, '|');				
					this->makeExchange(line, colorArr, color);
				}
				else
					first = false;
			}
		}
		catch (std::exception const & e)
			{
				color = static_cast<unsigned short int>(((static_cast<unsigned int>(color)) + 1) % 2);
				MySty::addWhat(e.what(), colorArr[color]);
			}
		nLine++;	
	}	
	if (first)
		throw std::invalid_argument("the input file is empty");
}
	