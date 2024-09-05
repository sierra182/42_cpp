/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 10:25:28 by seblin           ###   ########.fr       */
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

double	PmergeMe::calculateTime(std::clock_t start, std::clock_t end) const
{
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

PmergeMe::PmergeMe(char *argv[])
{
	this->Vector(argv);
	this->Deque(argv);
	// Parser psr;
	// std::istringstream iss;
	// std::string item;	
	// int value = 0;
	// long unsigned int nValue = 0;
	// 
	// char **argv_sav = argv;
	// while (*++argv)
	// {	
	// 	iss.clear();	
	// 	iss.str(std::string(*argv));		
	// 	while (std::getline(iss >> std::ws, item, ' '))
	// 	{
	// 		value = psr.parseToInt(item.begin(), item.end());
	// 		if (value < 0)		
	// 			throw std::invalid_argument
	// 				(std::string("the value must be positive: ") + item);		
	// 		fillA(value);		
	// 		if (++nValue > 100000)
	// 			throw std::invalid_argument
	// 				(std::string("the max value is reached: 100000"));
	// 	}		
	// }
	// fillA(-1);
	// std::cout << "n value: " << nValue << std::endl;
	// this->vectB.reserve((nValue / 2) + 1);
	// this->vectC.reserve(nValue);
	// std::clock_t start = std::clock();
	
	// this->printPair(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());
	// this->printCont(this->vectB);
	
	// std::cout << "sort vectA" << std::endl;	

	// std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin(); 		
	// if (!this->vectA.empty())
	// 	while (startA + 1 != this->vectA.end())	
	// 	{
	// 		// std::vector<std::pair<int, int> >::iterator startATmp = startA;
	// 		this->firstBinarySort(++startA, this->vectA.end(), this->vectA.begin(), startA);		
	// 		// printPairVector(this->vectA, startA, this->vectA.end(), this->vectA.begin(), startATmp);
	// 		if (startA != this->vectA.end())
	// 		{
	// 			// std::cout << "\e[" << this->vectA.size() + 1 << "A" << std::flush;
	// 			// usleep(1000000);
	// 		}
	// 	}
		
	// // return;
	
	// // std::cout << "vectA" << std::endl;
	// // printPairVector(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());

	// std::cout << "sort vectA 00" << std::endl;	
	// {
		
	// std::vector<std::pair<int, int> >::iterator startA = this->vectA.begin();
			
	// 	while (startA != this->vectA.end())	
	// 	{
	// 		this->binarySort(startA++, --this->vectA.end(), this->vectB.begin(), --this->vectB.end());
	// 		// printPairVector(this->vectA, this->vectA.begin(), this->vectA.end(), this->vectA.begin(),  this->vectA.end());
	// 		if (startA != this->vectA.end())
	// 		{
	// 			// std::cout << "\e[" << this->vectA.size() + 1 << "A" << std::flush;
	// 			// usleep(1000000);
	// 		}
	// 	}				
	// }
		
	// // std::cout << "print vect B" << std::endl;		
	// // printVector(this->vectB);
	
	// this->mergeSort(this->vectA.begin(), this->vectA.end(), this->vectB.begin(), this->vectB.end());
	
	// std::cout << "print vect C" << std::endl;	
	// // printVector(this->vectC);
	
	// std::clock_t end = std::clock();
	// std::cout << calculateTime(start, end) << std::endl;
	// this->checkFinal(this->vectC, nValue);
	// this->PmergeMeDeq(argv_sav);
}

