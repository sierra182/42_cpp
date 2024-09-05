/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 10:11:43 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Parser.hpp"
#include <sstream>

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
// template <class T>
// void printPairVector(std::T<std::pair<int, int> > const & vect,
// std::T<std::pair<int, int> >::iterator startA, std::T<std::pair<int, int> >::iterator endA
// , std::T<std::pair<int, int> >::iterator startB, std::T<std::pair<int, int> >::iterator endB)
// {
// 	for (std::vector<std::pair<int, int> >::const_iterator it = vect.begin(); it != vect.end(); it++)
// 	{		
// 		if (it == startA)
// 			std::cout << "\e[32m";	
// 		if (it == startB)
// 			std::cout << "\e[34m";
// 		if (it == endA)
// 			std::cout << "\e[31m";
// 		if (it == endB)
// 			std::cout << "\e[35m";	
// 		std::cout << it->first << ", " << it->second << "\e[0m" << std::endl;
// 		// if (it == endA)
// 		// 	std::cout << "\e[31m";
// 		// else if (it == endB)
// 		// 	std::cout << "\e[35m";			
// 	}	
// 	std::cout << "\e[0m" << std::endl;
// }

// void printVector(std::vector<int> const & vect)
// {
// 	std::cout << "print vector:" << std::endl;
// 	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
// 	{
// 		std::cout << *it << std::flush;
// 		std::cout << "\r" ;
// 	}
// 	std::cout << "end" << std::endl;
// }

// void checkFinalVector(std::vector<int> vect, long unsigned int len)
// {
// 	if (len != vect.size())
// 		std::cout << "\e[31m Error: final size : " << vect.size() << ", needed: " << len << std::endl;
// 	std::vector<int>::iterator it = vect.begin();
// 	std::vector<int>::iterator it_tmp = vect.begin();
// 	for (; it != vect.end(); it++)
// 	{
// 		if (*it >= *it_tmp)
// 		{
// 			it_tmp = it;
// 		}
// 		else
// 		{
// 			std::cout << "\e[31m Error: " << *it << ", " << *it_tmp
// 				<< "\e[0m" << std::endl;
// 			return;
// 		}
// 	}
// 	std::cout << "\e[32m no problemo\e[0m" << std::endl;
// }

double	PmergeMe::calculateTime(std::clock_t start, std::clock_t end) const
{
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

void 	PmergeMe::fillA(int value)
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

void PmergeMe::binarySort(std::vector<std::pair<int, int> >::iterator startA,
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
		this->binarySort(startA, endA, startB, --middle);		
	else if (startA->second > *middle)
		this->binarySort(startA, endA, ++middle, endB);	 
}

void PmergeMe::mergeSort(std::vector<std::pair<int, int> >::iterator startA,
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

void PmergeMe::firstBinarySort(
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
		this->firstBinarySort(startA, endA, startB, --middle);
	else if (startA->first > middle->first)
		this->firstBinarySort(startA, endA, ++middle, endB);
}

PmergeMe::PmergeMe(char *argv[])//! check doublons  //reserve // const!
{
	Parser psr;
	std::istringstream iss;
	std::string item;	
	int value = 0;
	long unsigned int nValue = 0;
	// 
	char **argv_sav = argv;
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
			fillA(value);		
			if (++nValue > 100000)
				throw std::invalid_argument
					(std::string("the max value is reached: 100000"));
		}		
	}
	fillA(-1);
	std::cout << "n value: " << nValue << std::endl;
	this->vectB.reserve((nValue / 2) + 1);
	this->vectC.reserve(nValue);
	std::clock_t start = std::clock();
	
	this->printPair(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());
	this->printCont(this->vectB);
	
	std::cout << "sort vectA" << std::endl;	

	std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin(); 		
	if (!this->vectA.empty())
		while (startA + 1 != this->vectA.end())	
		{
			// std::vector<std::pair<int, int> >::iterator startATmp = startA;
			this->firstBinarySort(++startA, this->vectA.end(), this->vectA.begin(), startA);		
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

	std::cout << "sort vectA 00" << std::endl;	
	{
		
	std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin();
			
		while (startA != this->vectA.end())	
		{
			this->binarySort(startA++, --this->vectA.end(), this->vectB.begin(), --this->vectB.end());
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
	
	this->mergeSort(this->vectA.begin(), this->vectA.end(), this->vectB.begin(), this->vectB.end());
	
	std::cout << "print vect C" << std::endl;	
	// printVector(this->vectC);
	
	std::clock_t end = std::clock();
	std::cout << calculateTime(start, end) << std::endl;
	this->checkFinal(this->vectC, nValue);
	this->PmergeMeDeq(argv_sav);
}

