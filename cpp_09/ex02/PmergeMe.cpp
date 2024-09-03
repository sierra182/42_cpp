/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/03 15:10:43 by seblin           ###   ########.fr       */
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
// std::vector<int> D;
// std::vector<int> C;
// void PmergeMe::binarySort(std::vector<int>::iterator startA, std::vector<int>::iterator endA
// , std::vector<int>::iterator startB, std::vector<int>::iterator endB)
// {
// 	std::vector<int>::iterator middle = startB;
// 	std::advance(middle, std::distance(startB, endB) / 2);
// 	std::cout << "start is : " << *startB <<  " MID is " << *middle << " end is : " << *endB <<
// 	 " DIST: " << std::distance(startB, endB) << std::endl;
// 	if (std::distance(startB, endB) < 0)
// 	{
// 		if (startB == endB && startB != C.end())
// 			std::cout << "start b egal end: " << *startB++ << " endb " <<  *endB << std::endl;
			
// 		std::cout << "the position is: " << *startB << " " <<  *startA << std::endl;
// 		// if (startB >= vectB.begin() && startB <= vectB.end()) 			
// 		// {
// 			// std::cout << "the position is: " << *startB << " " <<  *startA << std::endl;
// 			 C.insert(startB, *startA);
// 			//  D.erase(startA);
// 			 std::cout << "PRINT C" << std::endl;
// 			 printVector(C);
// 			  std::cout << "PRINT D" << std::endl;
// 			 printVector(D);
// 		// }
// 		// else
// 		// 	std::cout << "pb" << std::endl;
// 		// if (startA != endA)
// 		 	// binarySort(startA, endA, C.begin(), C.end());
// 		if (++startA != D.end())//endA)
// 		{
// 			 binarySort(startA, endA, C.begin(), --C.end());
// 			//  binarySort(startA, endA, C.begin(), --C.end());
// 			// binarySort(D.begin(), --D.end(), C.begin(), --C.end());
// 		}
// 		 	std::cout << "start is end end: " << std::endl; //binarySort(D.begin(), D.end(), C.begin(), C.end());
// 		// binarySort(startA, endA, this->vectB.begin(), this->vectB.end());
// 		return ; 
// 	}
// 	if (*startA < *middle)
// 	{
// 		// endB = --middle;
// 		binarySort(startA, endA, startB, --middle);
// 	}
// 	else// if (*startA > *middle)
// 	{		
// 		// startB = ++middle;
// 		binarySort(startA, endA, ++middle, endB);
// 	}
// 	// else 
// 	// {
// 	// 	std::cout << "the position is: middle:" << *middle << std::endl;   
// 	// 	return ;
// 	// }
// }


void PmergeMe::binarySort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA
, std::vector<int>::iterator startB, std::vector<int>::iterator endB)
{
	std::vector<int>::iterator middle = startB;
	std::advance(middle, std::distance(startB, endB) / 2);

	if (std::distance(startB, endB) < 0)
	{	
		this->vectB.insert(startB, startA->second);	
		if (++startA != this->vectA.end())		
			binarySort(startA, endA, this->vectB.begin(), --this->vectB.end());
		return ; 
	}
	if (startA->second < *middle)
		binarySort(startA, endA, startB, --middle);	
	else //!else if
		binarySort(startA, endA, ++middle, endB);	
}
PmergeMe::PmergeMe(char *argv[])//! check doublons  //reserve
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
	
	// int arr[] = {02, 12, 33, 78, 80, 85, 100};
	// C.assign(arr, arr + 7);
	// int arr2[] = {199, 15, 7, 6, 0, 199, 99};
	// D.assign(arr2, arr2 + 7);
	// binarySort(D.begin(), --D.end(), C.begin(), --C.end());	
	binarySort(this->vectA.begin(), --this->vectA.end(), this->vectB.begin(), --this->vectB.end());	
	std::cout << "print vect B" << std::endl;		
	printVector(this->vectB);	
	// printVector(D);		
}



	// std::cout <<  "D  DIST: " << std::distance(D.begin(), D.end()) << std::endl;
	// std::cout <<  "C  DIST: " << std::distance(C.begin(), C.end()) << std::endl;