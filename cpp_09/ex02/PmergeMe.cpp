/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/03 11:46:28 by seblin           ###   ########.fr       */
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

void	PmergeMe::calculateTime()
{
	std::clock_t start = std::clock();
	std::clock_t end = std::clock();

	double span = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	(void) span;
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

void printPairVector(std::vector<std::pair<int, int> > const & vect)
{
	std::cout << "print pair vector:" << std::endl;
	for (std::vector<std::pair<int, int> >::const_iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << it->first << ", " << it->second << std::endl;
	std::cout << "end" << std::endl;
}

void printVector(std::vector<int> const & vect)
{
	std::cout << "print vector:" << std::endl;
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "end" << std::endl;
}

void PmergeMe::binarySort(std::vector<int>::iterator startA, std::vector<int>::iterator endA
, std::vector<int>::iterator startB, std::vector<int>::iterator endB)
{
	// std::vector<int>::iterator middle = std::next(startB, std::distance(startB, endB) * 0.5);
	std::vector<int>::iterator middle = startB;
	std::advance(middle, std::distance(startB, endB) / 2);
	if (std::distance(endB, startB) > 0)
	{
		std::cout << "the position is: " << *startB << std::endl;
		return ; 
	}
	if (*startA < *middle)
	{
		endB = --middle;
		binarySort(startA, endA, startB, endB);
	}
	else if (*startA > *middle)
	{		
		startB = ++middle;
		binarySort(startA, endA, startB, endB);
	}
	else 
	{
		std::cout << "the position is: middle:" << *middle << std::endl;   
		return ;
	}


	
}

PmergeMe::PmergeMe(char *argv[])//! check doublons 
{
	Parser psr;
	std::istringstream iss;
	std::string item;	
	int value = 0;
	// int n_value = 0;
	
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
		}
		
	}
	fillA(-1);
	printPairVector(this->vectA);
	printVector(this->vectB);
	
	std::cout << "sort vectA" << std::endl;		
	std::sort(this->vectA.begin(), this->vectA.end());
	printPairVector(this->vectA);
	
	int arr[] = {02, 12, 33, 78, 80, 85, 100};
	std::vector<int> C(arr, arr + 7);
	int arr2[] = {80, 12, 33, 78, 80, 18, 100};
	std::vector<int> D(arr2, arr2 + 7);
	binarySort(D.begin(), D.end(), C.begin(), C.end());			
}