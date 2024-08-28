/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/28 16:17:26 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include "MyStyl.hpp"

#include <map>

bool parseDate(std::string date, std::string::iterator & it,  int max, int delim)
{
	int nbr = 0;
	
	
	while (it != date.end() && *it != delim)
	{
		while (std::isspace(*it))
			it = date.erase(it);
		while (std::isdigit(*it))
			nbr++; 
		if (nbr > max)
			return std::cout << "too much digit" << std::endl, false;
		if (!std::isdigit(*it))
			return std::cout << "not digit" << std::endl, false;		
	}
	return true;
}

void	parseLine(std::string line)
{
	std::map<std::string, float> mymap;
	std::string::iterator it = line.begin();
	if (parseDate(line, it, 4, '-') && parseDate(line, it, 2, '-') && parseDate(line, it, 2, '|'))
	{
		
		// line.substr(0, std::distance(line.begin(), it));
	}	
	
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
		std::cout << line << std::endl;
		// line.find()
		
	}	
		
	
	(void) argc, (void) argv;
	return (0);
}