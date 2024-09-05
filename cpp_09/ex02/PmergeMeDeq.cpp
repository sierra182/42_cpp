/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 15:51:00 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void PmergeMe::inBinarySortDeq(
	long unsigned int startA, long unsigned int endA,
	long unsigned int startB, long unsigned int endB)
{
	long unsigned int middle = ((endB - startB) / 2) + startB;
			
	if (endB < startB || this->deqA[startA].first == this->deqA[middle].first 
		|| (this->deqA[startA].first < this->deqA[middle].first
		&& middle == 0))
	{						
		std::pair<int, int> startA_tmp = this->deqA[startA];		
		std::deque<std::pair<int, int> >::iterator itStartA
		= this->deqA.begin();
		std::advance(itStartA, startA);
		this->deqA.erase(itStartA);		
		itStartA = this->deqA.begin();	
		std::advance(itStartA, startB);								
		this->deqA.insert(itStartA, startA_tmp);
		return ;
	}	
	if (this->deqA[startA].first < this->deqA[middle].first)
		this->inBinarySortDeq(startA, endA, startB, --middle);
	else if (this->deqA[startA].first > this->deqA[middle].first)
		this->inBinarySortDeq(startA, endA, ++middle, endB);
}

void PmergeMe::binarySortDeq(
	std::deque<std::pair<int, int> >::iterator startA,
	std::deque<std::pair<int, int> >::iterator endA,
	std::deque<int>::iterator startB,
	std::deque<int>::iterator endB)
{
	std::deque<int>::iterator middle = startB;

	std::advance(middle, std::distance(startB, endB) / 2);
	if (std::distance(startB, endB) < 0 || startA->second == *middle
		|| (startA->second < *middle && middle == this->deqB.begin()))	
	{	
		this->deqB.insert(startB, startA->second);	
		return ; 
	}
	else if (startA->second < *middle)	
		this->binarySortDeq(startA, endA, startB, --middle);		
	else if (startA->second > *middle)
		this->binarySortDeq(startA, endA, ++middle, endB);	 
}

void PmergeMe::mergeSortDeq(
	std::deque<std::pair<int, int> >::iterator startA,
	std::deque<std::pair<int, int> >::iterator endA,
	std::deque<int>::iterator startB,
	std::deque<int>::iterator endB)
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

void PmergeMe::argHandleDeq(char *argv[], long unsigned int & nValue,
	void (PmergeMe::*fill)(int))
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
			(this->*fill)(value);		
			if (++nValue > 100000)
				throw std::invalid_argument
					(std::string("the max value is reached: 100000"));
		}		
	}
	(this->*fill)(-1);
}

std::pair<double, long unsigned int> PmergeMe::Deque(char *argv[])
{	
	long unsigned int nValue = 0;

	this->argHandleDeq(argv, nValue, &PmergeMe::fillADeq);
	std::clock_t start = std::clock();
	
	long unsigned tmp = 0;	
	long unsigned int startA = 0;
	long unsigned int endA = this->deqA.size() - 1;	

	while (!this->deqA.empty() && startA != this->deqA.size() - 1)
	{
		tmp = startA++;	
		this->inBinarySortDeq(startA, endA, 0, tmp);
	}
	{		
		std::deque<std::pair<int, int> >::iterator startA = this->deqA.begin();	
		if (this->deqB.empty())
		{
			this->deqB.insert(this->deqB.begin(), this->deqA.begin()->second);		
			startA++;	
		}		
		while (startA != this->deqA.end())
			this->binarySortDeq(startA++, --this->deqA.end(),
				this->deqB.begin(), --this->deqB.end());	
	}	
	this->mergeSortDeq(this->deqA.begin(), this->deqA.end(),
		this->deqB.begin(), this->deqB.end());
	
	std::clock_t end = std::clock();	
	double time = calculateTime(start, end);
	this->checkFinal(this->deqC, nValue);
	std::cout << std::endl;
	return (std::make_pair(time, nValue));
}

