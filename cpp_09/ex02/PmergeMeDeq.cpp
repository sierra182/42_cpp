/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 10:23:26 by seblin           ###   ########.fr       */
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

void PmergeMe::binarySortDeq(std::deque<std::pair<int, int> >::iterator startA,
	std::deque<std::pair<int, int> >::iterator endA,
	std::deque<int>::iterator startB, std::deque<int>::iterator endB)
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

void PmergeMe::mergeSortDeq(std::deque<std::pair<int, int> >::iterator startA,
	std::deque<std::pair<int, int> >::iterator endA,
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

void PmergeMe::firstBinarySortDeq(
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
		this->firstBinarySortDeq(startA, endA, startB, --middle);
	else if (this->deqA[startA].first > this->deqA[middle].first)
		this->firstBinarySortDeq(startA, endA, ++middle, endB);
}

void PmergeMe::Deque(char *argv[])
{
	Parser psr;
	std::istringstream iss;
	std::string item;	
	int value = 0;
	long unsigned int nValue = 0;
	
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
			if (++nValue > 100000)
				throw std::invalid_argument
					(std::string("the max value is reached: 100000"));
		}		
	}
	fillADeq(-1);
	std::cout << "n value: " << nValue << std::endl;
	std::clock_t start = std::clock();
	
	this->printPair(this->deqA, this->deqA.begin(), this->deqA.end(), this->deqA.begin(),  this->deqA.end());
	this->printCont(this->deqB);
	
	std::cout << "sort deqA" << std::endl;	
	// std::sort(this->deqA.begin(), this->deqA.end());
	
	long unsigned tmp;	
	long unsigned int startA = 0;
	long unsigned int endA = this->deqA.size() - 1;	
		
	while (!this->deqA.empty() && startA != this->deqA.size() - 1)
	{
		tmp = startA++;
		// startA++;
		this->firstBinarySortDeq(startA, endA, 0, tmp);	
		// printPairDeq(this->deqA, this->deqA.begin(), this->deqA.end(), this->deqA.begin(),  this->deqA.end());
		if (startA != this->deqA.size() - 1)
		{
			// std::cout << "\e[" << this->deqA.size() << "A" << std::flush;
			// usleep(100000);
		}
	}	
	
	// std::cout << "deqA" << std::endl;
	// printPairVector(this->deqA, this->deqA.begin(), this->deqA.end(), this->deqA.begin(),  this->deqA.end());
	std::cout << "sort deqA 1 " << std::endl;
		
	std::deque<std::pair<int, int> >::iterator startAA = this->deqA.begin();	
	
	while (startAA != this->deqA.end())
	{
		
		this->binarySortDeq(startAA++, --this->deqA.end(), this->deqB.begin(), --this->deqB.end());	
		if (startAA != this->deqA.end())
		{
			// std::cout << "\e[" << this->deqA.size() << "A" << std::flush;
			// usleep(100000);
		}
	}				
	
	// std::cout << "print vect B" << std::endl;		
	// printVector(this->deqB);
	
	this->mergeSortDeq(this->deqA.begin(), this->deqA.end(), this->deqB.begin(), this->deqB.end());
	
	std::clock_t end = std::clock();
	std::cout << "print deq C" << std::endl;	
	// printDeq(this->deqC);
	
	std::cout << calculateTime(start, end) << std::endl;
	this->checkFinal(this->deqC, nValue);
}

