/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:10 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 22:25:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "Parser.hpp"

class BitcoinExchange
{
	std::map<std::string, float> inputMap;
	std::map<std::string, float> dataMap;
	
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange & src );
	BitcoinExchange & operator=( const BitcoinExchange & rhs);
		
	int		searchIndex(std::map<std::string, float> map,
		std::string const & key);
	void	isWrongDate(int year, int month, int day);
	void	checkDate(std::string & line);
	bool	parseDate(std::string & date, std::string::iterator & it,
			int max, int delim);
	void	parseLine(std::string & line,
		std::map<std::string, float> & inputMap, char sep);
	void	colorFullLine(const std::string & str, short unsigned int color);
	void	printRslt(const std::map<std::string, float>::const_iterator itInp,
			const std::map<std::string, float>::const_iterator itData,
			short unsigned int colorArr[], short unsigned int color);
	void	makeExchange(std::string const & line,
		short unsigned int colorArr[], short unsigned int color);
	void	fillDataMap(std::ifstream & infData);
	void	fillInputMap(std::ifstream & infInp);
	bool	isFirstLineValid(std::string line, Parser & parser,
		std::string const & comp1, char const comp2,
		std::string const & comp3);
		
	public:
		
		BitcoinExchange(std::ifstream & infData, std::ifstream & infInp);
		~BitcoinExchange( void );	
};
