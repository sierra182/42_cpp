/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVect.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 11:19:55 by seblin           ###   ########.fr       */
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

void PmergeMe::binarySortVect(std::vector<std::pair<int, int> >::iterator startA,
	std::vector<std::pair<int, int> >::iterator endA,
	std::vector<int>::iterator startB, std::vector<int>::iterator endB)
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

void PmergeMe::mergeSortVect(std::vector<std::pair<int, int> >::iterator startA,
	std::vector<std::pair<int, int> >::iterator endA,
	std::vector<int>::iterator startB, std::vector<int>::iterator endB)
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

void PmergeMe::firstBinarySortVect(
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
		this->firstBinarySortVect(startA, endA, startB, --middle);
	else if (startA->first > middle->first)
		this->firstBinarySortVect(startA, endA, ++middle, endB);
}

std::pair<double, long unsigned int> PmergeMe::Vector(char *argv[])
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
			fillAVect(value);		
			if (++nValue > 100000)
				throw std::invalid_argument
					(std::string("the max value is reached: 100000"));
		}		
	}
	fillAVect(-1);
	// std::cout << "n value: " << nValue << std::endl;
	this->vectB.reserve((nValue / 2) + 1);
	this->vectC.reserve(nValue);
	std::clock_t start = std::clock();
	
	// this->printPair(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());
	// this->printCont(this->vectB);
	
	// std::cout << "sort vectA" << std::endl;	

	std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin(); 		
	if (!this->vectA.empty())
		while (startA + 1 != this->vectA.end())	
		{
			// std::vector<std::pair<int, int> >::iterator startATmp = startA;
			this->firstBinarySortVect(++startA, this->vectA.end(), this->vectA.begin(), startA);		
			// printPairVector(this->vectA, startA, this->vectA.end(), this->vectA.begin(), startATmp);
			if (startA != this->vectA.end())
			{
				// std::cout << "\e[" << this->vectA.size() + 1 << "A" << std::flush;
				// usleep(1000000);
			}
		}
		
	// return;
	
	// std::cout << "vectA" << std::endl;
	// printPairVector(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());

	// std::cout << "sort vectA 00" << std::endl;	
	{
		
	std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin();
			
		while (startA != this->vectA.end())	
		{
			this->binarySortVect(startA++, --this->vectA.end(), this->vectB.begin(), --this->vectB.end());
			// printPairVector(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());
			if (startA != this->vectA.end())
			{
				// std::cout << "\e[" << this->vectA.size() + 1 << "A" << std::flush;
				// usleep(1000000);
			}
		}				
	}
		
	// std::cout << "print vect B" << std::endl;		
	// printVector(this->vectB);
	
	this->mergeSortVect(this->vectA.begin(), this->vectA.end(), this->vectB.begin(), this->vectB.end());
	
	// std::cout << "print vect C" << std::endl;	
	printCont(this->vectC);
	
	std::clock_t end = std::clock();
	double time = calculateTime(start, end);
	this->checkFinal(this->vectC, nValue);
	return (std::make_pair(time, nValue));
}

