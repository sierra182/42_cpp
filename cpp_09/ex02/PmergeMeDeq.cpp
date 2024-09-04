/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/04 16:48:34 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Parser.hpp"
#include <sstream>

void 	PmergeMe::fillADeq(int value)
{	
	static int lcl_value = -1;
	
	if (value < 0 && lcl_value >= 0)	
		this->deqB.push_back(lcl_value);	
	else if (lcl_value < 0)		
		lcl_value = value;	
	else
	{	
		if (value < lcl_value)		
			this->deqA.push_back(std::make_pair(value, lcl_value));	
		else
			this->deqA.push_back(std::make_pair(lcl_value, value));
		lcl_value = -1;
	}		
}

void printPairDeq(std::deque<std::pair<int, int> > const & vect,
std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA
, std::deque<std::pair<int, int> >::iterator startB, std::deque<std::pair<int, int> >::iterator endB)
{
	std::cout << "print pair deque:" << std::endl;
	for (std::deque<std::pair<int, int> >::const_iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (it == startA)
			std::cout << "\e[32m";	
		else if (it == startB)
			std::cout << "\e[34m";
		std::cout << it->first << ", " << it->second << std::endl;
		if (it == endA)
			std::cout << "\e[31m";
		else if (it == endB)
			std::cout << "\e[35m";	
	}
	std::cout << "end" << std::endl;
	std::cout << "\e[0m";
}

void printDeq(std::deque<int> const & vect)
{
	std::cout << "print deque:" << std::endl;
	for (std::deque<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "end" << std::endl;
}

void PmergeMe::binarySortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA
, std::deque<int>::iterator startB, std::deque<int>::iterator endB)
{
	std::deque<int>::iterator middle = startB;
	std::advance(middle, std::distance(startB, endB) / 2);

	if (std::distance(startB, endB) < 0 || startA->second == *middle
		|| (startA->second < *middle && middle == this->deqB.begin()))	
	{	
		this->deqB.insert(startB, startA->second);	
		// if (++startA != this->deqA.end())		
		// 	this->binarySortDeq(startA, endA, this->deqB.begin(), --this->deqB.end());
		return ; 
	}
	else if (startA->second < *middle)	
		this->binarySortDeq(startA, endA, startB, --middle);		
	else if (startA->second > *middle)
		this->binarySortDeq(startA, endA, ++middle, endB);	 
}


void PmergeMe::mergeSortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA,
std::deque<int>::iterator startB, std::deque<int>::iterator endB)
{
	while (startA != endA && startB != endB)
	{		
		if (startA->first < *startB)
			this->deqC.push_back(startA++->first);
		else
			this->deqC.push_back(*startB++);		
	}
	while (startA != endA)	
		this->deqC.push_back(startA++->first);	
	while (startB != endB)
		this->deqC.push_back(*startB++);
}

void PmergeMe::firstBinarySortDeq(long unsigned int startA, long unsigned int endA
, long unsigned int startB, long unsigned int endB)
{
	long unsigned int middle = ((endB - startB) / 2) + startB;
			
	if (endB < startB || this->deqA[startA].first == this->deqA[middle].first 
		|| (this->deqA[startA].first < this->deqA[middle].first && middle == 0))
	{
		std::pair<int, int> startA_tmp = this->deqA[startA];		
		std::deque<std::pair<int, int> >::iterator itStartA = this->deqA.begin();
		std::advance(itStartA, startA);
		this->deqA.erase(itStartA);
		std::deque<std::pair<int, int> >::iterator itStartB = this->deqA.begin();
		std::advance(itStartB, startB);								
		this->deqA.insert(itStartB, startA_tmp);									
		if (++startA != this->deqA.size())
			this->firstBinarySortDeq(startA, this->deqA.size() - 1, 0, startA - 1);
		return ; 
	}	
	if (this->deqA[startA].first < this->deqA[middle].first)
		this->firstBinarySortDeq(startA, endA, startB, --middle);
	else if (this->deqA[startA].first > this->deqA[middle].first)
		this->firstBinarySortDeq(startA, endA, ++middle, endB);
}

void checkFinalDeq(std::deque<int> deq)
{
	std::deque<int>::iterator it = deq.begin();
	std::deque<int>::iterator it_tmp = deq.begin();
	for (; it != deq.end(); it++)
	{
		if (*it >= *it_tmp)
		{
			it_tmp = it;
		}
		else
		{
			std::cout << "\e[31m Error: " << *it << ", " << *it_tmp << "\e[0m" << std::endl;
			return;
		}
	}
	std::cout << "\e[32m no problemo\e[0m" << std::endl;
}

void PmergeMe::PmergeMeDeq(char *argv[])//! check doublons // const!
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
			fillADeq(value);
		}
		
	}
	fillADeq(-1);
	std::clock_t start = std::clock();
	
	// printPairDeq(this->deqA, this->deqA.begin(), this->deqA.end(), this->deqA.begin(),  this->deqA.end());
	// printDeq(this->deqB);
	
	std::cout << "sort deqA" << std::endl;	
	// std::sort(this->deqA.begin(), this->deqA.end());
	
	// if (!this->deqA.empty())
	// 	this->firstBinarySortDeq(++this->deqA.begin(), this->deqA.end(), this->deqA.begin(), this->deqA.begin());

	if (!this->deqA.empty())
		this->firstBinarySortDeq(1, this->deqA.size() - 1, 0, 0);

	// std::cout << "deqA" << std::endl;
	// printPairVector(this->deqA, this->deqA.begin(), this->deqA.end(), this->deqA.begin(),  this->deqA.end());
	std::cout << "sort deqA 1 " << std::endl;
	// if (!this->deqA.empty())	
	// 	this->binarySortDeq(this->deqA.begin(), --this->deqA.end(), this->deqB.begin(), --this->deqB.end());	

		// if (!this->deqA.empty())	
		// this->binarySortDeq(this->deqA.begin(), --this->deqA.end(), this->deqB.begin(), --this->deqB.end());	
		
	std::deque<std::pair<int, int> >::iterator startA = this->deqA.begin();	
	if (!this->deqA.empty())		
		while (startA != this->deqA.end())					
			this->binarySortDeq(startA++, --this->deqA.end(), this->deqB.begin(), --this->deqB.end());	

	
	// std::cout << "print vect B" << std::endl;		
	// printVector(this->deqB);
	
	this->mergeSortDeq(this->deqA.begin(), this->deqA.end(), this->deqB.begin(), this->deqB.end());
	
	std::clock_t end = std::clock();
	std::cout << "print deq C" << std::endl;	
	// printDeq(this->deqC);		
	std::cout << calculateTime(start, end) << std::endl;
	checkFinalDeq(this->deqC);
}
//  "199 15 7 6 0 199 99 02 12 33 78 80 85 100" 1
