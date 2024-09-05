/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:09 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 10:14:38 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <ctime>
#include <sstream>
#include "Parser.hpp"
#include <unistd.h>

class PmergeMe
{
    std::vector<std::pair<int, int> >   vectA;
    std::vector<int>                    vectB;
    std::vector<int>                    vectC;
	
    std::deque<std::pair<int, int> >    deqA;
    std::deque<int>    					deqB;
	std::deque<int>   					deqC;
	
    PmergeMe();
    PmergeMe(const PmergeMe & src);
    PmergeMe & operator=(const PmergeMe & rhs);
    
	double	calculateTime(std::clock_t start, std::clock_t end) const;
    void    fillA(int value);

template < template <typename, typename> class T>
void printCont(T<int, std::allocator<int> > const & vect) const;

template < template < typename, typename > class T>
void printPair(
	const T<std::pair<int, int>, std::allocator<std::pair<int, int> > > &vect,
 	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::const_iterator startA, 
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::const_iterator endA,
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::iterator startB, 
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::iterator endB) const;

template < template < typename, typename > class T > 
void checkFinal(T<int, std::allocator<int> > vect, long unsigned int len) const;

void firstBinarySort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA
, std::vector<std::pair<int, int> >::iterator startB, std::vector<std::pair<int, int> >::iterator endB);

void binarySort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA
, std::vector<int>::iterator startB, std::vector<int>::iterator endB);

void mergeSort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA,
std::vector<int>::iterator startB, std::vector<int>::iterator endB);

    void    fillADeq(int value);

// void firstBinarySortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA
// , std::deque<std::pair<int, int> >::iterator startB, std::deque<std::pair<int, int> >::iterator endB);


void firstBinarySortDeq(long unsigned int startA, long unsigned int endA
, long unsigned int startB, long unsigned int endB);

void binarySortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA
, std::deque<int>::iterator startB, std::deque<int>::iterator endB);

void mergeSortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA,
std::deque<int>::iterator startB, std::deque<int>::iterator endB);
	void PmergeMeDeq(char * argv[]);



    public :
		
		PmergeMe(char * argv[]);
        ~PmergeMe();
};

template < template < typename, typename > class T >
void PmergeMe::printPair(
	const T<std::pair<int, int>, std::allocator<std::pair<int, int> > > &vect,
 	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::const_iterator startA, 
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::const_iterator endA,
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::iterator startB, 
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::iterator endB) const
{
	for (typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >::const_iterator it = vect.begin(); it != vect.end(); it++)
	{		
		if (it == startA)
			std::cout << "\e[32m";	
		if (it == startB)
			std::cout << "\e[34m";
		if (it == endA)
			std::cout << "\e[31m";
		if (it == endB)
			std::cout << "\e[35m";	
		std::cout << it->first << ", " << it->second << "\e[0m" << std::endl;
		// if (it == endA)
		// 	std::cout << "\e[31m";
		// else if (it == endB)
		// 	std::cout << "\e[35m";			
	}	
	std::cout << "\e[0m" << std::endl;
}

template < template < typename, typename > class T >
void PmergeMe::printCont(T<int, std::allocator<int> > const & vect) const
{
	std::cout << "print vector:" << std::endl;
	for (typename T<int, std::allocator<int> >::const_iterator it = vect.begin(); it != vect.end(); it++)
	{
		std::cout << *it << std::flush;
		// std::cout << "\r" ;
	}
	std::cout << "end" << std::endl;
}

template < template < typename, typename > class T > 
void PmergeMe::checkFinal(T<int, std::allocator<int> > vect, long unsigned int len) const
{
	if (len != vect.size())
		std::cout << "\e[31m Error: final size : " << vect.size() << ", needed: " << len << std::endl;
	typename T<int, std::allocator<int> >::iterator it = vect.begin();
	typename T<int, std::allocator<int> >::iterator it_tmp = vect.begin();
	for (; it != vect.end(); it++)
	{
		if (*it >= *it_tmp)
		{
			it_tmp = it;
		}
		else
		{
			std::cout << "\e[31m Error: " << *it << ", " << *it_tmp
				<< "\e[0m" << std::endl;
			return;
		}
	}
	std::cout << "\e[32m no problemo\e[0m" << std::endl;
}