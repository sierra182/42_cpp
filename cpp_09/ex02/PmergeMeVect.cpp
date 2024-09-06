/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVect.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/06 14:24:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void 	PmergeMe::fillAVect(int value)
{	
	static int lcl_value = -1;
	
	if (value < 0 && lcl_value >= 0)	
		this->vectB.push_back(lcl_value);	
	else if (lcl_value < 0)		
		lcl_value = value;	
	else
	{	
		if (value < lcl_value)		
			this->vectA.push_back(std::make_pair(value, lcl_value));	
		else
			this->vectA.push_back(std::make_pair(lcl_value, value));
		lcl_value = -1;
	}		
}

void PmergeMe::inBinarySortVect(
	std::vector<std::pair<int, int> >::iterator startA,
	std::vector<std::pair<int, int> >::iterator endA,
	std::vector<std::pair<int, int> >::iterator startB,
	std::vector<std::pair<int, int> >::iterator endB)
{
	std::vector<std::pair<int, int> >::iterator middle = startB;
	std::advance(middle, std::distance(startB, endB) / 2);	
		
	if (std::distance(startB, endB) < 0 || startA->first == middle->first
		|| (startA->first < middle->first && middle == this->vectA.begin()))	
	{				
		std::pair<int, int> startA_tmp = *startA;	
		startA = this->vectA.erase(startA);
		startB = this->vectA.insert(startB, startA_tmp);
		return ; 
	}	
	if (startA->first < middle->first)
		this->inBinarySortVect(startA, endA, startB, --middle);
	else if (startA->first > middle->first)
		this->inBinarySortVect(startA, endA, ++middle, endB);
}

void PmergeMe::binarySortVect(
	std::vector<std::pair<int, int> >::iterator startA,
	std::vector<std::pair<int, int> >::iterator endA,
	std::vector<int>::iterator startB,
	std::vector<int>::iterator endB)
{
	std::vector<int>::iterator middle = startB;
	std::advance(middle, std::distance(startB, endB) / 2);

	if (std::distance(startB, endB) < 0 || startA->second == *middle
		|| (startA->second < *middle && middle == this->vectB.begin()))	
	{	
		this->vectB.insert(startB, startA->second);	
		return ; 
	}
	else if (startA->second < *middle)	
		this->binarySortVect(startA, endA, startB, --middle);		
	else if (startA->second > *middle)
		this->binarySortVect(startA, endA, ++middle, endB);	 
}

void PmergeMe::mergeSortVect(
	std::vector<std::pair<int, int> >::iterator startA,
	std::vector<std::pair<int, int> >::iterator endA,
	std::vector<int>::iterator startB,
	std::vector<int>::iterator endB)
{
	while (startA != endA && startB != endB)
	{		
		if (startA->first < *startB)
			this->vectC.push_back(startA++->first);
		else
			this->vectC.push_back(*startB++);		
	}
	while (startA != endA)	
		this->vectC.push_back(startA++->first);	
	while (startB != endB)
		this->vectC.push_back(*startB++);
}

std::pair<double, long unsigned int> PmergeMe::Vector(char *argv[])
{	
	std::clock_t start = std::clock();	
	long unsigned int nValue = 0;	
	this->argHandle(argv, nValue, &PmergeMe::fillAVect);	
	this->vectB.reserve((nValue / 2) + 1);
	this->vectC.reserve(nValue);
	
	std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin(); 		
	if (!this->vectA.empty())
		while (startA + 1 != this->vectA.end())	
			this->inBinarySortVect(++startA, this->vectA.end(),
			this->vectA.begin(), startA);
		
	startA = this->vectA.begin();			
	if (this->vectB.empty())
	{
		this->vectB.insert(this->vectB.begin(), this->vectA.begin()->second);		
		startA++;	
	}	
	while (startA != this->vectA.end())		
		this->binarySortVect(startA++, --this->vectA.end(),
			this->vectB.begin(), --this->vectB.end());	
	this->mergeSortVect(this->vectA.begin(), this->vectA.end(),
		this->vectB.begin(), this->vectB.end());
			
	std::clock_t end = std::clock();
	double time = calculateTime(start, end);
	printCont(this->vectC);
	
	this->checkFinal(this->vectC, nValue);
	return (std::make_pair(time, nValue));
}
