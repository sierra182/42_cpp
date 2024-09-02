/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/02 12:46:35 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Parser.hpp"
#include <sstream>
#include <ctime>

PmergeMe::PmergeMe()
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe &)
{
    return ;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & )
{
    return (*this);
}

PmergeMe::~PmergeMe()
{
    return ;
}

void PmergeMe::calculateTime()
{
	std::clock_t start = std::clock();
	std::clock_t end = std::clock();

	double span = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void  PmergeMe::FordJhonson(int value)
{
	static bool flag ;
	int			tmp_value;
	
	if (!flag)
	{		
		tmp_value = value;
		flag = !flag;	
	}
	else
		this->vect.push_back(std::make_pair(tmp_value, value));	
		
}

PmergeMe::PmergeMe(char *argv[])//! check doublons 
{
	Parser psr;
	std::istringstream iss;
	std::string item;	
	int value = 0;

	while (*++argv)
	{	
		iss.clear();	
		iss.str(std::string(*argv));		
		while (std::getline(iss >> std::ws, item, ' '))
		{
			value = psr.parseToInt(item.begin(), item.end());
			if (value < 0)		
				throw std::invalid_argument
					(std::string("the value must be positive: ") + item);		
			FordJhonson(value);
		}
	}
}